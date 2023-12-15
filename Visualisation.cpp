#include "Visualisation.h"
#include <math.h>

Visualisation::Visualisation(int w, int h, double s, double l_pole, double s_cart){
    this->width = w;
    this->height = h;
    this->scale = s;
    this->len_pole = l_pole;
    this->size_cart = s_cart;
    this->window.create(sf::VideoMode(this->width, this->height), "Cartpole");
}

bool Visualisation::is_running(){
    return this->window.isOpen();
}

void Visualisation::check_close(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Visualisation::update(Vector2d state){

    Vector2d origin(this->width/2, this->height/2);

    Vector2d cart_pos(state(0), 0);
    Vector2d pole_offset(this->len_pole * sin(state(1)), this->len_pole * cos(state(1)));

    Vector2d cart_pos_vis;
    cart_pos_vis = this->scale * cart_pos + origin;

    Vector2d pole_pos_vis;
    pole_pos_vis = this->scale * (cart_pos + pole_offset) + origin;



    sf::RectangleShape cart_shape(sf::Vector2f(this->scale * this->size_cart, 
                                                this->scale * this->size_cart));
    cart_shape.setPosition(sf::Vector2f(cart_pos_vis(0) - (this->scale * this->size_cart)/2, 
                                        cart_pos_vis(1) - (this->scale * this->size_cart)/2));
    sf::Vertex pole[] =
    {
        sf::Vertex(sf::Vector2f(cart_pos_vis(0), cart_pos_vis(1))),
        sf::Vertex(sf::Vector2f(pole_pos_vis(0), pole_pos_vis(1)))
    };

    this->window.clear();
    this->window.draw(cart_shape);
    this->window.draw(pole,2, sf::Lines);
    this->window.display();

}

  
