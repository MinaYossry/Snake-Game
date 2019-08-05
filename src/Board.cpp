#include "Board.h"
#include "Game.h"

Board::Board() {
	for (int y{}; y < Game::totalDim; y += Cell::cellDim) {
		for (int x{}; x < Game::totalDim; x += Cell::cellDim) {
			board.emplace_back(std::make_shared<Cell>(Type::EMPTY, x, y));
		}
	}
}

void Board::drawBoard(sf::RenderWindow& window) const {
	for (const auto& cell : board) {
		window.draw(cell->getCell());
	}
}