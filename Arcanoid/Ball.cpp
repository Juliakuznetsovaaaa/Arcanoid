#pragma once
#include "Ball.hpp"
//#include "Source.cpp"
//#include <iostream>

//#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Ball::Ball()
{
	shape.setRadius(10.0f);
	shape.setFillColor(Color::Red);
	shape.setPosition(190, 510);
}

void Ball:: initLife() {
	for (int i = 0; i < 3; i++) {
		life[i].setRadius(20.0f);
		life[i].setFillColor(Color::Red);
		life[i].setPosition(10 + 45 * i, 5);
	}
}

//void Ball::update(double spin,int mx, int is_play, int l, int q, int ky)
//{
//    if (q != 24 && is_play==1) {
//
//        shape.move(velocity);
//        if (shape.getPosition().x < 0)
//            velocity.x = ballVelocity;
//        else if (shape.getPosition().x > 380)
//            velocity.x = -ballVelocity;
//
//        if (shape.getPosition().y < 50)
//            velocity.y = ballVelocity;
//        else if (shape.getPosition().y > 510) {
//            //velocity.y = -ballVelocity;
//            shape.setRadius(10.0f);
//            shape.setFillColor(Color::Red);
//            shape.setPosition(190, 510);
//            //man.setPosition(150, 530);
//            life[l].setFillColor(Color::Transparent);
//            l = l - 1;
//        }
//        if (l == -1) {
//            q = 24;
//            shape.setFillColor(Color::Transparent);
//            //man.setFillColor(Color::Transparent);
//        }
//    }
//}

