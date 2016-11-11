#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include <cmath>

using sf::Vector2f;
using sf::Vertex;
using sf::VertexArray;
using sf::Triangles;
using sf::Color;


class Character : public sf::Drawable, public sf::Transformable {
public:
	Character(float x, float y, float size);
	VertexArray vertices;
private:
	int addVertex(sf::Vertex);
	void createHead(float x, float y, float r);
	void createBody(float x, float y);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform(); // getTransform() is defined by sf::Transformable
		target.draw(vertices, states);
	}
};

#endif