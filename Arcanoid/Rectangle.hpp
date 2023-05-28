#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
//#include <iostream>
using namespace sf;
//unsigned int windowWidth = 400, windowHeight = 550;
class Rectangle {
public:
    RectangleShape shape;
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }
    void del() { shape.setPosition(500, 500); }
};

class Paddle : public Rectangle {
public:
    
    //Vector2f velocity;
    Paddle(float mX, float mY);
    void movePaddele();
    float getSizeX() { return shape.getSize().x; }
    //void update();
};

//enum class bonusType { none, moovingBlock, extraBall };

class Brick : public Rectangle {
public:
    int NUM_BLOCKS = 24;
    /*int hp;
    bonusType bonus;
    bool boost;*/
    Brick(float mX, float mY, const Color& color);
   
};

