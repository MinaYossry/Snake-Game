#pragma once
#include <vector>
#include <memory>
#include "Cell.h"

class Board
{
private:
	std::vector<std::shared_ptr<Cell>> board;
public:
	Board();
	void drawBoard(sf::RenderWindow& window) const;
};

