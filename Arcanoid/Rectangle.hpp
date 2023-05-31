#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Rectangle {
public:
    RectangleShape shape;
    /*float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getSize().x / 2.f; }
    float right() { return x() + shape.getSize().x / 2.f; }
    float top() { return y() - shape.getSize().y / 2.f; }
    float bottom() { return y() + shape.getSize().y / 2.f; }
    void del() { shape.setPosition(500, 500); }*/
};

class Paddle : public Rectangle {
public:
    
    Paddle() {};
    void init(float paddleWeidth);
   // void movePaddele();
    float getSizeX() { return shape.getSize().x; }
};


class Brick : public Rectangle {
public:
   
    int level;
    int bonusType;
    int NUM_BLOCKS = 24;
    Brick(float mX, float mY, const Color& color, int mLevel, int mBonusType);
    int getLevel() { return level; }
    void minLevel() { level--; }
    int getBonusType() { return bonusType; }

    /*int hp;
    bonusType bonus;
    bool boost;*/
    
};

