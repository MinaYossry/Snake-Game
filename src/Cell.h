#pragma once
#include <SFML/Graphics.hpp>

enum Type {
	EMPTY,
	SNAKE,
	FOOD
};

class Cell
{
private:
	sf::Sprite cell;
	sf::Texture color;
	sf::Vector2f position;
	Type type;
public:
	static const int cellDim{ 16 };
	Cell(Type type, int posX = 0, int posY = 0);
	sf::Sprite& getCell();
};

