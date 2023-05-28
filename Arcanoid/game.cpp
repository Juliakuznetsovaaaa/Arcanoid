#pragma once
#include "Ball.hpp"
#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <locale.h>
//#include "Source.cpp"
//#include "game.hpp"


using namespace sf;

int main() {
	
	setlocale(LC_ALL, "Russian");

	unsigned int windowWidth = 400, windowHeight = 550;
	RenderWindow window(VideoMode(400, 550), "Arcanoid");
	Paddle paddle(150, 530);
	Ball ball;
	std::vector<Brick> bricks;
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 8; j++) {
			bricks.emplace_back(50 * j, 50 * (i + 1), Color::Magenta);
			count++;
		}
	}
	std::cout << count;
	ball.initLife();
	double spin = 0.2;
	int is_play = 0;
	int l = 2;
	int p = 0;
	int q = 0;
	int ky = -1;
	int kx = -1;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		/*if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				is_play=1;
				
			}
		}*/
		Vector2f m = paddle.shape.getPosition();
				double spin = 0.12;
				if (q != 24) {
					if (Keyboard::isKeyPressed(Keyboard::Right))
						if (m.x < 300) {
							paddle.shape.move(spin, 0);
							if (p == 0)
								ball.shape.move(spin, 0);
						}
		
					if (Keyboard::isKeyPressed(Keyboard::Left))
						if (m.x > 0) {
							paddle.shape.move(-spin, 0);
							if (p == 0)
								ball.shape.move(-spin, 0);
						}
					if (event.type == Event::MouseButtonPressed) {
						if (event.key.code == Mouse::Left) {
							p = 1;
						}
					}
				}
				else {
					p = 0;
				}
				
				if (p == 1) {
					ball.shape.move(spin * kx, spin * ky);
					Vector2f b= ball.shape.getPosition();
					if (b.x < 0 || b.x>380)
						kx = -kx;
					if (b.y < 50)
						ky = -ky;
					if (b.x >= m.x - 15 && b.x <= m.x + 100 && b.y == 510)
						ky = -ky;
					if (b.y > 560) {
						p = 0;
						ky = -ky;
						paddle.shape.setPosition(150, 530);
						ball.shape.setPosition(190, 510);
						ball.life[l].setFillColor(Color::Transparent);
						l--;
					}
					if (l == -1) {
						q = 24;
						ball.shape.setFillColor(Color::Transparent);
						paddle.shape.setFillColor(Color::Transparent);
					}
					Vector2f bl[24];
					int i = 0;
					for (auto& brick : bricks) {
						bl[i] = brick.shape.getPosition();
						if (b.x>=bl[i].x && b.x <= bl[i].x+50)
							if (b.y < bl[i].y + 50 && b.y > bl[i].y) {
								ky = -ky;
								brick.shape.setPosition(500, 500); 
								q++;
							}
						i++;
					}
				}
		//		
		/*std::cout << " is_play = " << is_play << "\n";
		paddle.movePaddele();
		ball.update(spin, paddle.getSizeX(), is_play, l, q, ky);
		for (auto& brick : bricks) {
			bool is_del = testCollision(brick, ball);
			if (is_del) {
				q++;
			}
		}*/
		
		window.clear();
		for (auto& brick : bricks) window.draw(brick.shape);
		window.draw(paddle.shape);
		window.draw(ball.shape);
		for (int i = 0; i < 3; i++) {
			window.draw(ball.life[i]);
		}
		window.display();
	}
	return 0;
}
//int main() {
//	Game game;
//	return game.run();
//}

