#include <stdio.h>
#include <eigen3/Eigen/Dense>

#include "Controller.h"

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Vector2d;


Controller::Controller(MatrixXd kp, MatrixXd kd, MatrixXd ki,Vector2d s_des, Vector2d ds_des){
    this->Kp = kp;
    this->Kd = kd;
    this->Ki = ki;
    this->s_des = s_des;
    this->ds_des = ds_des;
    this->e_i = VectorXd::Zero(2);
}

Vector2d Controller::get_u(Vector2d s, Vector2d ds){
    e_i = e_i + (s_des - s);
    return this->Kp * (s_des - s) + this->Kd * (ds_des - ds) + this->Ki * e_i;
}
