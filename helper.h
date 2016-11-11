#ifndef HELPER_H
#define HELPER_H
#include <SFML/Graphics.hpp>
#include "constants.h"
#include <iostream>
#include <cmath>
#include <vector>

using sf::Vector2f;
using sf::Vertex;
using sf::VertexArray;
using sf::Triangles;
using sf::Color;
using std::vector;

class Helper {
public:
	static vector<Vertex> createSquare(Square square) {

		vector<Vertex> result;
		result.push_back(Vertex(Vector2f(square.x, square.y), square.color));
		result.push_back(Vertex(Vector2f(square.x + square.size, square.y + square.size),  square.color));
		result.push_back(Vertex(Vector2f(square.x, square.y + square.size), square.color));
		result.push_back(Vertex(Vector2f(square.x, square.y), square.color));
		result.push_back(Vertex(Vector2f(square.x + square.size, square.y),  square.color));
		result.push_back(Vertex(Vector2f(square.x + square.size, square.y + square.size), square.color));
		return result;
	};

	static vector<Vertex> createCircle(Circle circle) {
		vector<Vertex> result;

		float increment = circle.points ? 360 / circle.points : 12;

		for (float i = 0; i < 360; i += increment) {

			float p1x = circle.x + (circle.radius * cos(i * M_PI / 180.0));
			float p1y = circle.y + (circle.radius * sin(i * M_PI / 180.0));
			float p2x = circle.x + (circle.radius * cos((i + increment) * M_PI / 180.0));
			float p2y = circle.y + (circle.radius * sin((i + increment) * M_PI / 180.0));

			result.push_back(Vertex(Vector2f(circle.x, circle.y), circle.color));
			result.push_back(Vertex(Vector2f(p1x, p1y), circle.color));
			result.push_back(Vertex(Vector2f(p2x, p2y), circle.color));
		}
		return result;
	}
};

#endif