#include <SFML/Graphics.hpp>
#include "constants.h"
#include "character.h"

int main()
{
	srand(time(0));
	Character character(300, 300, 100);
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window", sf::Style::Default, settings);

	window.setFramerateLimit(60); // call it once, after creating the window
	float i = 0;

	sf::CircleShape circle(50, 60);
	circle.setFillColor(AQUA);
	circle.setPosition(100, 100);

	while (window.isOpen())
	{
		i += 0.01;
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		window.draw(character);
		window.draw(circle);

		window.display();
	}

	return 0;
}
