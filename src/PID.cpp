#include "PID.h"
#include <limits>
#include <iostream>

#define TUNING_TOLERANCE 0.2

int tuning_idx = 2;
int iteration = 0;
int stage = -1;
int valid_count = 0;

PID::PID() {
    this->Kp = 0.0;
    this->Ki = 0.0;
    this->Kd = 0.0;
    error_sum = 0.0;
    previous_error = 0.0;
    tune_parameters = true;
    parameters_store = new double[3] { 0.0, 0.0, 0.0 };
    parameters = new double[3] { 0.1, 0.001, 0.0 };
    d_params = new double[3] { 0.1, 0.1, 0.1 };
    best_error = std::numeric_limits<double>::max();
}

double PID::GetValue(double error) {
    if (tune_parameters) {
        //TuneParameters(error);
    }

    error_sum += error;
    double p = parameters[0] * error;
    double i = parameters[1] * error_sum;
    double d = parameters[2] * (error - previous_error);
    double value = -(p + i + d);
    return value;
}

double PID::GetTotalError() {

}

void PID::TuneParameters(double error) {
    // TODO: Use abs function
    if (error < 0) {
        error = -error;
    }

    stage++;
    int i = tuning_idx;

    if (stage == 0) {
        parameters[i] += d_params[i];
        return;
    }

    if (stage == 1) {
        if (error < best_error) {
            best_error = error;
            d_params[i] *= 1.1;
        }
        else {
            parameters[i] -= 2 * d_params[i];
        }
        return;
    }

    if (stage == 2) {
        if (error < best_error) {
            best_error = error;
            d_params[i] *= 1.1;
        }
        else {
            parameters[i] += d_params[i];
            d_params[i] *= 0.9;
        }
    }

    stage = -1;
    iteration++;

    if (error < 0.1) {
        valid_count++;
    }

    if (valid_count == 50) {
        valid_count = 0;
        std::cout << "Final value for idx " << i << ": " << parameters[i] << std::endl;
        tuning_idx++;
        if (tuning_idx == 3) {
            tune_parameters = false;
            parameters = parameters_store;
        }
        else {
            parameters_store[i] = parameters[i];
            // TODO: Implement reset method
            parameters[0] = 0;
            parameters[1] = 0;
            parameters[2] = 0;
            iteration = 0;
            error_sum = 0;
            previous_error = 0;
            best_error = std::numeric_limits<double>::max();
        }
    }
}
