#include "gnome.h"

Gnome::Gnome(float x, float y, float size) {

	float hatSize = size;
	float headSize = size / 8;

	createHead(x, y + hatSize - (headSize / 2), headSize);
	createHat(x, y, hatSize);
}

void Gnome::move(float x, float y) {
	head.move(x, y);
	hat.move(x, y);
}

void Gnome::createHead(float x, float y, float r) {
	head.setRadius(r);
	head.setFillColor(sf::Color::Green);
	//head.setOrigin(Vector2f(x, y));
	head.setPosition(Vector2f(x, y));
}

void Gnome::createHat(float x, float y, float size) {

	float length = size;
	float width = size / 4;

	Vector2f origin = head.getPosition();
	origin.x += head.getRadius();
	origin.y += head.getRadius();

	hat.setOrigin(origin);

	hat.setPosition(origin);
	hat.setPointCount(3);
	hat.setPoint(0, Vector2f(x + width / 2, y));
	hat.setPoint(1, Vector2f(x + width, y + length));
	hat.setPoint(2, Vector2f(x, y + length));
	hat.rotate(20);
	hat.setFillColor(sf::Color::Red);
}


void Gnome::draw(sf::RenderWindow & window) {
	window.draw(head);
	window.draw(hat);
}
