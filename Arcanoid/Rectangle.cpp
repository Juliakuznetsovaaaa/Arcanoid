#include "Rectangle.hpp"
#include <iostream>
using namespace std;
Paddle::Paddle(float mX, float mY)
{
	shape.setSize(Vector2f(100, 10));
	shape.setPosition(mX, mY);
	shape.setFillColor(Color::Red);
	
}

void Paddle::movePaddele()
{
	double spin = 0.1;
	
	float paddleVelocity = 8.5f;
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		if (shape.getPosition().x < 300) {
			shape.move(spin, 0);
			
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
		if (shape.getPosition().x > 0) {
			shape.move(-spin, 0);
		}
							
}

Brick::Brick(float mX, float mY, const Color& color)
{
	shape.setPosition(mX, mY);
	shape.setSize(Vector2f(50, 50));
	shape.setFillColor(color);
}


