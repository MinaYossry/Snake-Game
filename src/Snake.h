#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Cell.h"
#include "Fruit.h"

enum direction {
	STOP = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake
{
private:
	std::vector<std::shared_ptr<Cell>> snakeBody;
	std::shared_ptr<Cell> head;
	direction dir;
	bool lost;
	bool changedDir;
	
public:
	Snake();
	void drawSnake(sf::RenderWindow& window) const;
	void setDir(direction newDir);
	void movement();
	void eatFruit(Fruit& apple);
	void checkIfHitItself();
	void moveHead();
	void moveBody();
	bool Lost() const;
	bool outOfFrame();
	static int score;
};

