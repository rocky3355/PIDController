#include "PID.h"

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
    double value = -(p + i + d);
    return value;
}

double PID::GetTotalError() {

}

double* RunTwiddle(double tolerance = 0.2) {
    double p[3] = { 0.0, 0.0, 0.0 };
    double dp[3] = { 1.0, 1.0, 1.0 };

    PID pid(p[0], p[1], p[2]);
    double best_error = pid.GetValue();

    //it = 0
    while (dp[0] + dp[1] + dp[2] > tolerance) {
        //print("Iteration {}, best error = {}".format(it, best_err))
        for (uint i = 0; i < 3; i++) {
            p[i] += dp[i]
            robot = make_robot()
            x_trajectory, y_trajectory, err = run(robot, p)

            if (err < best_err) {
                best_err = err;
                dp[i] *= 1.1;
            }
            else {
                p[i] -= 2 * dp[i];
                robot = make_robot();
                x_trajectory, y_trajectory, err = run(robot, p);

                if (err < best_err) {
                    best_err = err;
                    dp[i] *= 1.1;
                }
                else {
                    p[i] += dp[i]
                    dp[i] *= 0.9
                }
            }
            //it += 1
        }
    }
    return p
}
