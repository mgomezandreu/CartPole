#include <stdio.h>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Vector2d;

class Controller{
    private:
    MatrixXd Kp;
    MatrixXd Kd;
    MatrixXd Ki;

    Vector2d s_des;
    Vector2d ds_des;
    Vector2d e_i;

    public:
    Controller(MatrixXd Kp, MatrixXd Kd, MatrixXd Ki, Vector2d s_des, Vector2d ds_des);
    Vector2d get_u(Vector2d s, Vector2d ds);

};
