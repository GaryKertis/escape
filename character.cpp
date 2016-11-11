#include "character.h"

Character::Character(float x, float y, float size) {
	vertices = VertexArray(Triangles, 0);
	createHead(x, y, size / 2);
	createBody(x, y + size);
}

void Character::createHead(float x, float y, float r) {
	Circle circle = {
		x,
		y,
		r,
		DARKAQUA,
		100
	};

	vector<Vertex> result = Helper::createCircle(circle);

	for (auto & point : result) {
		vertices.append(point);
	}
}

void Character::createBody(float x, float y) {
	Square square = {
		x,
		y,
		100.0,
		AQUA
	};

	vector<Vertex> result = Helper::createSquare(square);

	for (auto & point : result) {
		vertices.append(point);
	}
}

int Character::addVertex(Vertex vertex) {
	vertices.append(vertex);
	return vertices.getVertexCount() - 1;
}
