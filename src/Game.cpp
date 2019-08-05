#include <iostream>
#include <string>
#include "Game.h"
#include "Fruit.h"

void Game::startGame() {
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(totalDim, totalDim), "Snake");
	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(20);
	Board board;
	Snake snake;
	Fruit apple;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					std::cout << "Moving up" << std::endl;
					snake.setDir(UP);
				}
				else if (event.key.code == sf::Keyboard::Down) {
					std::cout << "Moving down" << std::endl;
					snake.setDir(DOWN);
				}
				else if (event.key.code == sf::Keyboard::Left) {
					std::cout << "Moving LEFT" << std::endl;
					snake.setDir(LEFT);
				}
				else if (event.key.code == sf::Keyboard::Right) {
					std::cout << "Moving RIGHT" << std::endl;
					snake.setDir(RIGHT);
				}
				else if (event.key.code == sf::Keyboard::Space) {
					snake.setDir(STOP);
				}
			}
		}
		if (!snake.Lost()) {
			snake.movement();
			snake.eatFruit(apple);
			window.clear();
			board.drawBoard(window);
			snake.drawSnake(window);
			apple.drawFruit(window);
			window.display();
		}
		else {
			window.clear();
			endGame(window);
			window.display();
		}
	}
}

void Game::endGame(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("font/arial.ttf");
	sf::Text text;
	text.setFont(font);
	std::string str = "You Lost\nScore: " + std::to_string(Snake::score);
	text.setString(str);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	window.draw(text);
}