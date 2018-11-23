#ifndef PID_H
#define PID_H

class PID {
    double p_error;
    double i_error;
    double d_error;

    double Kp;
    double Ki;
    double Kd;

    double error_sum;
    double previous_error;
    bool tune_parameters;

    double* parameters;
    double* parameters_store;
    double* d_params;
    double best_error;
    
    void TuneParameters(double error);
public:
    PID();
    double GetValue(double error);
    double GetTotalError();
    //void SetError(double error);
};

#endif /* PID_H */
