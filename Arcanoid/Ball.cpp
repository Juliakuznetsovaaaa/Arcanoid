#pragma once
#include "Ball.hpp"
//#include "Source.cpp"
//#include <iostream>

//#include <SFML/Graphics.hpp>
//using namespace std;
using namespace sf;

void Ball::BallInit(float mX,float mY)
{
	shape.setRadius(10.0f);
	shape.setFillColor(Color::Red);
	shape.setPosition(mX- 10, mY);
}

void Ball:: initLife() {
	for (int i = 0; i < 3; i++) {
		life[i].setRadius(20.0f);
		life[i].setFillColor(Color::Red);
		life[i].setPosition(10 + 45 * i, 5);
	}
}

BonusDrop::BonusDrop(float mX, float mY, Color color, int BonusType)
{
	shape.setRadius(10.0f);
	shape.setFillColor(color);
	shape.setPosition(mX, mY);
	bonusType = BonusType;
}
