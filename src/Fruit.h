#pragma once
#include <memory>
#include "Cell.h"


class Fruit
{
private:
	std::shared_ptr<Cell> fruit;
public:
	Fruit();
	void drawFruit(sf::RenderWindow& window) const;
	std::shared_ptr<Cell> getFruit() const;
	void generatePos();
};

