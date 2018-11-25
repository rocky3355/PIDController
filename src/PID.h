#ifndef PID_H
#define PID_H

class PID {
    double Kp;
    double Ki;
    double Kd;

    double error_sum;
    double previous_error;
public:
    PID(double kp, double ki, double kd);
    double GetValue(double error);
};

#endif /* PID_H */
