#include "PID.h"
#include <iostream>

PID::PID(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    error_sum = 0.0;
    previous_error = 0.0;
}

double PID::GetValue(double error) {
    error_sum += error;
    double p = Kp * error;
    double i = Ki * error_sum;
    double d = Kd * (error - previous_error);
    previous_error = error;

    double value = -(p + i + d);
    return value;
}
