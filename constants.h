#ifndef CONSTANTS_H
#define CONSTANTS_H

using sf::Color;

const int WINDOWWIDTH = 800;
const int WINDOWHEIGHT = 600;
const Color LITEAQUA(63, 189, 164);
const Color AQUA(54, 182, 157);
const Color DARKAQUA(34, 131, 112);

struct Square {
	float x;
	float y;
	float size;
	Color color;
};

struct Circle {
	float x;
	float y;
	float radius;
	Color color;
	int points;
};

#endif