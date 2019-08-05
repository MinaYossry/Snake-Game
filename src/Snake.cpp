#include "Snake.h"
#include "Board.h"
#include "Game.h"
#include <iostream>

int Snake::score = 0;

Snake::Snake()
	: dir{ STOP }, lost{ false }, changedDir{ false } {
	head = std::make_shared<Cell>(SNAKE, Game::totalDim / 2, Game::totalDim / 2);
	snakeBody.emplace_back(head);
}

void Snake::drawSnake(sf::RenderWindow& window) const {
	for (const auto& cell : snakeBody) {
		window.draw(cell->getCell());
	}
}

void Snake::setDir(direction newDir) {
	if ((newDir == UP && dir != DOWN)
		|| (newDir == DOWN && dir != UP)
		|| (newDir == RIGHT && dir != LEFT)
		|| (newDir == LEFT && dir != RIGHT)) {
			dir = newDir;
			changedDir = true;
			moveBody();
			moveHead();
			checkIfHitItself();
	}
	else if (newDir == STOP) {
		dir = newDir;
	}
}

void Snake::movement() {
	if (!changedDir) {
		if (dir != STOP) {
			moveBody();
			moveHead();
			checkIfHitItself();
		}
	}
	else {
		changedDir = false;
	}
}

void Snake::eatFruit(Fruit& apple) {
	if (apple.getFruit()->getCell().getPosition() == head->getCell().getPosition()) {
		apple.generatePos();
		int newX = head->getCell().getPosition().x;
		int newY = head->getCell().getPosition().y;
		snakeBody.emplace_back(std::make_shared<Cell>(SNAKE, newX, newY));
		score++;
	}
}

void Snake::checkIfHitItself() {
	for (auto body = snakeBody.cbegin() + 1; body != snakeBody.cend(); body++) {
		if (head->getCell().getPosition() == (*body)->getCell().getPosition()) {
			lost = true;
			std::cout << "Lost" << std::endl;
		}
	}
}

bool Snake::Lost() const {
	return lost;
}

void Snake::moveBody() {
	for (size_t part{ snakeBody.size() - 1 }; part > 0; part--) {
		*(snakeBody.at(part)) = *(snakeBody.at(part - 1));
	}
}

void Snake::moveHead() {
	if (dir == UP) {
		head->getCell().move(0.0, float(-Cell::cellDim));
		if (head->getCell().getPosition().y < 0)
			head->getCell().move(0.0, float(Game::totalDim));
	}
	else if (dir == DOWN) {
		head->getCell().move(0.0, float(Cell::cellDim));
		if (head->getCell().getPosition().y >= Game::totalDim)
			head->getCell().move(0.0, float(-Game::totalDim - Cell::cellDim));
	}
	else if (dir == RIGHT) {
		head->getCell().move(float(Cell::cellDim), 0.0);
		if (head->getCell().getPosition().x >= Game::totalDim)
			head->getCell().move(float(-Game::totalDim - Cell::cellDim), 0.0);
	}
	else if (dir == LEFT) {
		head->getCell().move(float(-Cell::cellDim), 0.0);
		if (head->getCell().getPosition().x < 0)
			head->getCell().move(float(Game::totalDim), 0.0);
	}
}

bool Snake::outOfFrame() {
	return ((head->getCell().getPosition().y < 0)
		|| (head->getCell().getPosition().y >= Game::totalDim)
		|| (head->getCell().getPosition().x >= Game::totalDim)
		|| (head->getCell().getPosition().x < 0));
}