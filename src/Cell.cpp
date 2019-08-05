#include "Cell.h"

Cell::Cell(Type type, int posX, int posY)
	: type{ type } {
	position = sf::Vector2f(float (posX), float (posY));
	if (type == EMPTY)
		color.loadFromFile("images/white.png");
	else if (type == SNAKE)
		color.loadFromFile("images/red.png");
	else
		color.loadFromFile("images/green.png");
	cell.setTexture(color);
	cell.setTextureRect(sf::IntRect(0, 0, cellDim, cellDim));
	cell.setPosition(position);
}

sf::Sprite& Cell::getCell() {
	return cell;
}