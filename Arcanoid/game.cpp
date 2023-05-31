 #pragma once
#include "game.hpp"
#include <iostream>

using namespace sf;

static int random(int min, int max) {
	return min + rand() % (max - min + 1);
}

void fillField(vector<Brick>& bricks, int& q) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			int mlevel = random(1, 4);
			if (mlevel == 1) {
				if (i==0||j==50) {
						bricks.emplace_back(50 * j, 50 * (i + 1), Color(105, 33, 60, 255), 0, 0);//неразрушимый(самый темный)
						q++;
				
				}
				else if (random(1, 2) % 2 == 0) {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(255, 162, 87, 255), 1, 1);// цвет макароны и сыр, замедл€ет шарик

				}
				else if (random(1, 5) % 3 == 1) {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(250, 0,89, 255), 1, 4);//одноразовое дно

				}
				else {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(255, 168, 175, 255), 1, 0);//нежно-розовыйй, как пион
					
				}
			}
			else if (mlevel == 2) {
				if (random(1, 10) % 8== 0) {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(227, 66, 52, 255), 1, 2);//китайский красный, не сильно темный, увеличивает каретку
				}
				else if (random(1, 10) % 3 == 0) {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(252, 196, 206, 255), 1, 5);// рутой розовыб шарик мен€ет напрвление

				}
				else {
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(255, 73, 108, 255), 2, 0);//розовый как барби
				}
			}
			else if (mlevel == 3) {
				if (random(1, 10)%7==0)
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(176, 0, 0, 255), 1, 3);//бордо, «амирание
				else
					bricks.emplace_back(50 * j, 50 * (i + 1), Color(224, 52, 75, 255), 3, 0);
			}

			else {
				bricks.emplace_back(50 * j, 50 * (i + 1), Color(255, 168, 175, 255), 1, 0);
				//bricks.emplace_back(50 * j, 50 * (i + 1), Color(205, 74, 76, 255), 1, 4);//одноразовое дно

			}
			
		}
	}
}

void movePaddleAndBall(int& p, Vector2f& paddleCoordinates, Paddle& paddle, Ball& ball, int windowWidth, float& paddelWeigth) {
	double spinBall = 0.52;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		if (paddleCoordinates.x < windowWidth - paddelWeigth) {
			paddle.shape.move(spinBall, 0);
			if (p == 0)
				ball.shape.move(spinBall, 0);
		}

	if (Keyboard::isKeyPressed(Keyboard::Left))
		if (paddleCoordinates.x > 0) {
			paddle.shape.move(-spinBall, 0);
			if (p == 0)
				ball.shape.move(-spinBall, 0);
		}
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		p = 1;
	}
}

void moveBall(int& kx, int& ky, Vector2f& ballCoordinates, Vector2f& paddleCoordinates, bool& is_zaliz, int& p, float& paddelWeigth, double& spin) {
	if (ballCoordinates.x < 0 || ballCoordinates.x>580)
		kx = -kx;
	if (ballCoordinates.y < 50)
		ky = -ky;
	if (ballCoordinates.x >= ballCoordinates.x - 15 && ballCoordinates.x >= paddleCoordinates.x && ballCoordinates.x <= paddleCoordinates.x + paddelWeigth && ballCoordinates.y > 710 && ballCoordinates.y < 711) {
		if (is_zaliz) {
			p = 0;
			is_zaliz = false;
		}
		if (spin != 0.2) {
			spin = 0.2;
		}
		ky = -ky;
	}
}
void bonusBallActive(vector<BonusDrop>& bonusBall, bool& is_bonusBal, vector<bool>& is_active, Vector2f& paddleCoordinates, Paddle& paddle, float* delBrick, bool& is_zaliz, int& count, float& paddelWeigth, double& spin, VertexArray& line, bool& is_line, bool& is_change_position) {
	int i = 0;
	for (auto& bBall : bonusBall) {
		if (is_active[i]) {
			switch (bBall.getBonusType())
			{
			case 1:
				spin = 0.1;
				cout << "case1" << "\n";
				break;
			case 2:
				paddle.shape.setSize(Vector2f(paddelWeigth + 30, 10));
				cout << "case2" << "\n";
				break;
			case 3:
				is_zaliz = true;
				cout << "case3" << "\n";
				break;
			case 4:
				line[0].color = Color::Red; // задание цвета первой вершины
				line[1].color = Color::White; // задание цвета второй вершины
				is_line = true;
				cout << "case4" << "\n";
				break;
			case 5:
				is_change_position = true;
				cout << "case5" << "\n";
				break;
			default:
				break;
			}
			delBrick[0] = -1; delBrick[1] = -1; delBrick[2] = -1;
			is_active[i] = false;	
		}
		i++;
	}

	
	
	
}


void delLife(Vector2f& ballCoordinates, Paddle& paddle, int& ky, int score, Text& text, Ball& ball, int& p, int& l, int& q, float& paddelWeigth, VertexArray& line, bool& is_line) {
	if (ballCoordinates.y > 760) {
		p = 0;
		ky = -ky;
		paddelWeigth -= 30;
		paddle.init(paddelWeigth);
		ball.shape.setPosition(290, 710);
		if (!is_line) {
			ball.life[l].setFillColor(Color::Transparent);
			l--;
		}
		else {
			line[0].color = Color::Transparent; 
			line[1].color = Color::Transparent;
			is_line = false;
		}
		score -= 1;
		text.setString("Score: " + std::to_string(score));
	}
	if (l == -1) {
		q = 72;
		ball.shape.setFillColor(Color::Transparent);
		paddle.shape.setFillColor(Color::Transparent);
	}
}
void updateBrickLevel(int brickLevel, Brick& brick) {
	switch (brickLevel)
	{
	case 1:
		brick.shape.setFillColor(Color(255, 168, 175, 255));
		break;
	case 2:
		brick.shape.setFillColor(Color(255, 73, 108, 255));
		break;
	default:
		break;
	}
}
void delBlock(vector<Brick>& bricks, Vector2f& ballCoordinates, float* delBrick, vector<BonusDrop>& bonusBall, bool& is_bonusBal, int& count, int& score, Text& text, int& kx, int& ky, vector<bool>& is_active) {
	Vector2f bl[72];
	int i = 0;
	//cout << is_bonusBal << "\n";
	for (auto& brick : bricks) {
		bl[i] = brick.shape.getPosition();
		
		if (ballCoordinates.x >= bl[i].x && ballCoordinates.x <= bl[i].x + 50)
			if (ballCoordinates.y <= bl[i].y + 50 && ballCoordinates.y >= bl[i].y) {
				ky = -ky;
				if (brick.getLevel() == 1) {
					brick.minLevel();
					Color bBallColor = brick.shape.getFillColor();
					score++;
					text.setString("Score: " + std::to_string(score));

					delBrick[0] = brick.shape.getPosition().x;
					delBrick[1] = brick.shape.getPosition().y;
					delBrick[2] = brick.getBonusType();
					brick.shape.setPosition(1200, 1200);
					if (delBrick[2] > 0) {
						bonusBall.emplace_back(delBrick[0], delBrick[1], bBallColor, delBrick[2]);
						is_active.push_back(false);
						count++;
						cout << count;
						bonusBall[count].shape.move(0, 0.3);
						is_bonusBal = true;
					}
				}
				else {
					brick.minLevel();
					updateBrickLevel(brick.getLevel(), brick);
					kx = -kx;
				}
			}
		i++;
	}
}
void bonusBallmove(vector<BonusDrop>& bonusBall, bool& is_bonusBal, vector<bool>& is_active, Vector2f& paddleCoordinates, Paddle& paddle, float* delBrick, bool& is_zaliz, int& count, float& paddelWeigth, double& spin, VertexArray& line, bool& is_line, bool& is_change_position) {
	int i = 0;
	
	for (auto& bBall : bonusBall) {

		Vector2f bB = bBall.shape.getPosition();
		if (bB.x >= paddleCoordinates.x && bB.x <= (paddleCoordinates.x + paddelWeigth) && bB.y > 710 && bB.y < 714) {
			bBall.shape.setPosition(1200, 1200);
			is_active[i]=true;
			cout <<" this is active " << i << "\n";
		}
		i++;

	}
}
int Game:: run() {
	
	setlocale(LC_ALL, "Russian");
	
	unsigned int windowWidth = 600, windowHeight = 800;
	
	int l = 2; int p = 0; int q = 0; int count = 0;
	bool is_zaliz = false;
	bool is_bonusBal = false;
	vector<bool> is_active = { false };
	std::vector<BonusDrop> bonusBall;
	bonusBall.emplace_back(1200, 1200, Color::White, 1);

	//is_active.push_back(false); 
	float delBrick[] = { -1, -1, -1 };
	int score = 0;
	double spin = 0.2;
	float paddelWeigth = 200;
	int ky = -1;
	int kx = -1;
	
	RenderWindow window(VideoMode(600, 800), "Arcanoid");
	Paddle paddle;

	VertexArray line(Lines, 2); // создание объекта линии с двум€ вершинами
	line[0].position = Vector2f(0, 750); // задание координат первой вершины
	line[1].position = Vector2f(600, 750); // задание координат второй вершины
	line[0].color = Color::Transparent; // задание цвета первой вершины
	line[1].color = Color::Transparent; // задание цвета второй вершины
	bool is_line = false; 
	bool is_change_position = false;
	paddle.init(paddelWeigth);
	Ball ball;
	ball.BallInit((windowWidth - paddelWeigth)/2+(paddelWeigth/2), 710);
	
	std::vector<Brick> bricks;
	fillField(bricks, q);
	ball.initLife();

	Font font;
	font.loadFromFile("ArialRegular.ttf"); 
	Text text;
	text.setFont(font);
	text.setString("Score: " + std::to_string(score)); 
	text.setCharacterSize(24);
	text.setPosition(400, 0);
	text.setFillColor(Color::White);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		Vector2f m = paddle.shape.getPosition();
		if (q !=72) {
			movePaddleAndBall(p, m, paddle, ball, windowWidth, paddelWeigth);
		}
		else {
			p = 0;
		}
		if (p == 1) {
			ball.shape.move(spin * kx, spin * ky);
			Vector2f b= ball.shape.getPosition();
			for (auto& bBall: bonusBall)
				bBall.shape.move(0, 0.3);
			Vector2f bB = bonusBall[count].shape.getPosition();
			moveBall(kx, ky, b, m, is_zaliz, p, paddelWeigth,spin);
			bonusBallmove(bonusBall, is_bonusBal, is_active, m, paddle, delBrick, is_zaliz, count, paddelWeigth, spin, line, is_line, is_change_position);
			
			bonusBallActive(bonusBall, is_bonusBal, is_active, m, paddle, delBrick, is_zaliz, count, paddelWeigth, spin, line, is_line, is_change_position);
			delLife(b, paddle, ky, score, text, ball, p, l, q, paddelWeigth, line, is_line);
			delBlock(bricks, b, delBrick, bonusBall, is_bonusBal, count, score, text, kx, ky, is_active);
			if (is_change_position && random(1, 90) % 8 == 0) {
				kx = -kx;
				ky = -ky;
				is_change_position = false;
			}
		}

		window.clear();
		for (auto& brick : bricks) window.draw(brick.shape);
		window.draw(paddle.shape);
		window.draw(ball.shape);
		window.draw(text);
		window.draw(line);
		for(auto& bBall: bonusBall)
			window.draw(bBall.shape);
		for (int i = 0; i < 3; i++) {
			window.draw(ball.life[i]);
		}
		window.display();
	}
	return 0;
}
int main() {
	Game game;
	return game.run();
}

