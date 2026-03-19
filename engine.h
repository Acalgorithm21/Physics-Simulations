#pragma once 

#include "ball.h"
#include "Force.h"



class Engine {
public:

    void applyForce(const Earth& earth, Ball& ball, float dt) {


        sf::Vector2f pos = ball.ball.getPosition();
        sf::Vector2f vel = ball.velocity;
    
        vel += earth.gravity * dt;
        pos += vel * dt;

        ball.update(vel, pos);

    };


};