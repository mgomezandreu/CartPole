#include "Cartpole.h"
#include <stdio.h>
#include <math.h>

Cartpole::Cartpole(double m_cart, double m_poletip, double l_pole){
    this->mass_cart = m_cart;
    this->mass_poletip = m_poletip;
    this->len_pole = l_pole;
    this->reset();
}

void Cartpole::reset(){
    this->s = VectorXd::Zero(2);
    this->s(1) =  M_PI - 0.5;
    this->ds = VectorXd::Zero(2);
}

void Cartpole::simulation_step(double u, double dt){
    double x = this->s(0);
    double theta = this->s(1);
    double dx = this->ds(0);
    double dtheta = this->ds(1);

    MatrixXd M{
        {this->mass_cart + this->mass_poletip, this->mass_poletip * this->len_pole * cos(theta)},
        {this->mass_poletip * this->len_pole * cos(theta), this->mass_poletip * this->len_pole * this->len_pole}
    };

    MatrixXd B{
        {0, - this->mass_poletip *dtheta * sin(theta)},
        {0,0}
    };
    Vector2d g(0,this->mass_poletip * 9.81 * this->len_pole * sin(theta));
    Vector2d f(u,0);
   
    VectorXd dds = VectorXd::Zero(2);
    dds = M.inverse() * (f - B*this->ds - g);

    this->ds = this->ds + dt * dds;
    this->s = this->s + dt* this->ds;

    //printf("x: %f, theta: %f\n", this->s(0), this->s(1));

}

VectorXd Cartpole::get_s(){
    return this->s;
}

VectorXd Cartpole::get_ds(){
    return this->ds;
}

