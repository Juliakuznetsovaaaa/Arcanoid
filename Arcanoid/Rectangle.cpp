#include "Rectangle.hpp"
#include <iostream>
//using namespace std;


void Paddle::init(float paddleWidth){
	unsigned int windowWidth = 600;
	shape.setSize(Vector2f(paddleWidth, 10));
	shape.setPosition((windowWidth- paddleWidth)/2, 730);
	shape.setFillColor(Color::Red);
}



Brick::Brick(float mX, float mY, const Color& color, int mLevel, int mBonusYype)
{
	shape.setPosition(mX, mY);
	shape.setSize(Vector2f(50, 50));
	shape.setFillColor(color);
	level = mLevel;
	bonusType = mBonusYype;
}


