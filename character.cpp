#include "character.h"

Character::Character(float x, float y, float size) {

	vertices = VertexArray(Triangles, 0);

	createHead(x, y, size / 2);
	createBody(x, y + size);
}

void Character::createHead(float x, float y, float r) {

	for (float i = 0; i < 360; i += 12) {

		float p1x = x + (r * cos(i * M_PI / 180.0));
		float p1y = y + (r * sin(i * M_PI / 180.0));

		float p2x = x + (r * cos((i + 12) * M_PI / 180.0));
		float p2y = y + (r * sin((i + 12) * M_PI / 180.0));

		Vertex vertex1(Vector2f(x, y), AQUA);
		Vertex vertex2(Vector2f(p1x, p1y),  AQUA);
		Vertex vertex3(Vector2f(p2x, p2y), AQUA);

		addVertex(vertex1);
		addVertex(vertex2);
		addVertex(vertex3);
	}
}

void Character::createBody(float x, float y) {

	float bodySize = 100;

	Vertex vertex1(Vector2f(x, y), AQUA);
	Vertex vertex2(Vector2f(x + bodySize, y + bodySize),  AQUA);
	Vertex vertex3(Vector2f(x, y + bodySize), AQUA);

	addVertex(vertex1);
	addVertex(vertex2);
	addVertex(vertex3);

	Vertex vertex4(Vector2f(x, y), AQUA);
	Vertex vertex5(Vector2f(x + bodySize, y),  AQUA);
	Vertex vertex6(Vector2f(x + bodySize, y + bodySize), AQUA);

	addVertex(vertex4);
	addVertex(vertex5);
	addVertex(vertex6);
}

int Character::addVertex(Vertex vertex) {
	vertices.append(vertex);
	return vertices.getVertexCount() - 1;
}
