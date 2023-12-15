#include <stdio.h>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;

using Eigen::Vector2d;

class Cartpole{
    private:
    VectorXd s; // x, theta
    VectorXd ds;

    double mass_cart;
    double mass_poletip;
    double len_pole;

    public:
    Cartpole(double m_cart, double m_poletip, double l_pole);
    VectorXd get_s();
    VectorXd get_ds();
    void reset();
    void simulation_step(double u, double dt);
}; 



