#pragma once
#include "settings.h"
struct Brick {
	sf::RectangleShape shape;
};
void brickInit(Brick& brick) {
	brick.shape.setSize(sf::Vector2f(brick_width, brick_height));
	brick.shape.setFillColor(brickColor);
	brick.shape.setPosition(brick_pos);
}
void updateGame(Brick& brick) {

}
