#pragma once
#include "Ball.hpp"
#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>
class Game {
public:
	int l = 3;
	bool is_play = false;
	int run();
};

int main();
