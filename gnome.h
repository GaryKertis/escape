#ifndef GNOME_H
#define GNOME_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "helper.h"
#include <vector>
#include <cmath>

using sf::Vector2f;
using sf::Vertex;
using sf::VertexArray;
using sf::Triangles;
using sf::Color;
using std::vector;

class Gnome {
public:
	Gnome(float x, float y, float size);
	void draw(sf::RenderWindow &);
	void move(float x, float y);
private:
	sf::CircleShape head;
	sf::ConvexShape hat;
	void createHat(float, float, float);
	void createHead(float, float, float);
};

#endif