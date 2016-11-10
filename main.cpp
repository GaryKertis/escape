#include <SFML/Graphics.hpp>
#include "constants.h"

int main()
{
	srand(time(0));

	// create the window
	sf::RenderWindow window(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), "My window");
	window.setFramerateLimit(60); // call it once, after creating the window

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		window.display();
	}

	return 0;
}
