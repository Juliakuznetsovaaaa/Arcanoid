#include <SFML/Graphics.hpp>
//#include "Rectangle.hpp"
#include <iostream>
//#include "Source.cpp"

using namespace std;
using namespace sf;

class Ball {
    
public:
    CircleShape shape;
    
    CircleShape life[3];
    //Vector2f velocity{ -ballVelocity, -ballVelocity };
    int  kx = -1;
    Ball();
    float ballRadius = 10.f;
    float ballVelocity = 0.1f;

    //unsigned int windowWidth = 400, windowHeight = 550;
    Vector2f velocity{ -ballVelocity, -ballVelocity };
    void initLife();

   // virtual void update(double spin, int mx, int is_play, int l, int q, int ky);
    float x() { return shape.getPosition().x; }
    float y() { return shape.getPosition().y; }
    float left() { return x() - shape.getRadius(); }
    float right() { return x() + shape.getRadius(); }
    float top() { return y() - shape.getRadius(); }
    float bottom() { return y() + shape.getRadius(); }
  

    	
};
