#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <eigen3/Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using Eigen::Vector2d;

class Visualisation{
    private:
    sf::RenderWindow window;
    double len_pole;
    double size_cart;
    double scale;
    int width;
    int height;

    public:
    Visualisation(int w, int h, double scale, double l_pole, double s_cart);
    bool is_running();
    void check_close();
    void update(Vector2d state);
};
