#pragma once
#include "SFML/Graphics.hpp"

class Ball {

private:
    sf::Vector2f position;
    sf::CircleShape ballShape;// A RectangleShape object called ref
    float radius = 10.0f;
    float xVelocity = 3.0f;
    float yVelocity = 4.0f;

public:
        Ball(float startX, float startY);
        sf::FloatRect getPosition();
        sf::CircleShape getShape();
        float getXVelocity();
        void reboundSides();
        void reboundBatOrTop();
        void hitBottom();
        void update();
};