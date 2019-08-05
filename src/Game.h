#pragma once
#include "Board.h"
#include "Snake.h"
#include "Cell.h"

class Game
{
private:
	
public:
	static const int numberOfCells{ 40 };
	static const int totalDim{ numberOfCells * Cell::cellDim };
	void startGame();
	void endGame(sf::RenderWindow& window);
};

