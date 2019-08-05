#include "Fruit.h"
#include "Game.h"

Fruit::Fruit()
	: fruit {std::make_shared<Cell>(FOOD)}{
	generatePos();
}

void Fruit::drawFruit(sf::RenderWindow& window) const {
	window.draw(fruit->getCell());
}

std::shared_ptr<Cell> Fruit::getFruit() const {
	return fruit;
}

void Fruit::generatePos() {
	int posX = rand() % Game::numberOfCells * Cell::cellDim;
	int posY = rand() % Game::numberOfCells * Cell::cellDim;
	fruit->getCell().setPosition(sf::Vector2f(float(posX), float(posY)));
}