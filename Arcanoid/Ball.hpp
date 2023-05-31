#include <SFML/Graphics.hpp>
//#include "Rectangle.hpp"
#include <iostream>


using namespace std;
using namespace sf;

class Ball {
public:
    CircleShape shape;
    CircleShape life[3];

    Ball(){}
    void BallInit (float mX, float mY);
    void initLife();
};

class BonusDrop :public Ball {
public:
        int bonusType;
    BonusDrop(float mX, float mY, Color color, int BonusType);
    int getBonusType() {
        return bonusType;
    }
};