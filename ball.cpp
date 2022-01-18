#include "ball.h"
#include "const.h"

// This the constructor and it is called when we create an object
Ball::Ball(float startX, float startY){
    ballShape.setRadius(radius);
    position.x = startX;
    position.y = startY;
    ballShape.setPosition(position);
}
sf::FloatRect Ball::getPosition(){ return ballShape.getGlobalBounds();}

sf::CircleShape Ball::getShape(){return ballShape;}

float Ball::getXVelocity(){    return xVelocity;}

void Ball::reboundSides(){    xVelocity = -xVelocity;}

void Ball::reboundBatOrTop(){
    //position.y -= (yVelocity * 30);
    yVelocity = -yVelocity;
}

void Ball::hitBottom(){
    position.y = 1;
    position.x = 500;
}

void Ball::update()
{
    // Update the ball position variables
    position.y += yVelocity;
    position.x += xVelocity;
    // Move the ball 
    ballShape.setPosition(position);
    //проверка на столкновения
    if (getPosition().top + 2*radius > SCREEN_HEIGHT) {
        // reverse the ball direction
        //hitBottom();
        reboundBatOrTop();
    }

    // Handle ball hitting top
    if (getPosition().top < 0)   {
        reboundBatOrTop();
    }

    // Handle ball hitting sides
    if (getPosition().left < 0 || getPosition().left + 2*radius > SCREEN_WIDTH){
        reboundSides();
    }
     
}