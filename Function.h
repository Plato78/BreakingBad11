#pragma once
#include "SFML/Graphics.hpp"
#include "BAT.h"
#include "BALL.h"
#include "Textobj.h"
//ÁÈÒÀ
bool pointInRect(Bat& bat, sf::Vector2f point) {
	return (point.x >= bat.shape.getPosition().x && point.x <= bat.shape.getPosition().x + bat_width) &&
		(point.y >= bat.shape.getPosition().y && point.y <= bat.shape.getPosition().y + bat_height);
}

void batInit(Bat& bat) {
	bat.shape.setSize(sf::Vector2f(bat_width, bat_height));
	bat.shape.setFillColor(Bat_Color);
	bat.shape.setPosition(bat_start_pos);
	bat.speedx = 0.f;
}
void batControl(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))bat.speedx = -bat_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))bat.speedx = bat_speed;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}
void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= width - bat_width)
		bat.shape.setPosition(width - bat_width, baty);

}
//ØÀÐ
void ballInit(Ball& ball) {
	ball.shape.setRadius(ballradius);
	ball.shape.setFillColor(ballColor);
	ball.shape.setPosition((width - 2 * ballradius) / 2,
		(height - 2 * ballradius) / 2);	//ball_start_pos
	ball.ball_speed = 0.f;

}
void BallMove(Ball& ball) {
	ball.shape.move(ball_dx, ball_dy);
	float arr_speed[]{ -5.f,-4.f,-3.f, -2.f, -1.f, 1.f, 2.f, 3.f, 4.f, 5.f };
	int index = rand() % 10;
	float ball_speedx = arr_speed[index];
	index = rand() % 10;
	float ball_speedy = arr_speed[index];
	srand(time(nullptr));
}
void  ballReboundEdges(Ball& ball) {
	ball.shape.move(ball_dx, ball_dy);
	if (ball.shape.getPosition().x <= 0)
	{
		ball_dx = -ball_dx;

	}
	if (ball.shape.getPosition().x >= (width - 2 * ballradius))
	{
		ball_dx = -ball_dx;
	}
	if (ball.shape.getPosition().y <= 0 || ball.shape.getPosition().y >= (height - 2 * ballradius)) {
		ball_dy = -ball_dy;
	}

}
void drawGame(sf::RenderWindow& window, Ball ball) {
	window.clear();
	window.draw(ball.shape);
	window.display();
}

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void updateGame(Bat& bat, Ball& ball, Textobj& text,int score) {
	batControl(bat);
	batReboundEdges(bat);
	BallMove(ball);
	ballReboundEdges(ball);
	textUpdate(text, score);
}

void checkCollision(Bat& bat, Ball& ball) {
	// кто в кого попал, пересекся и что с этим делать 
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + ballradius
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + ballradius,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * ballradius,
		ball.shape.getPosition().y + ballradius
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + ballradius,
		ball.shape.getPosition().y + 2 * ballradius
	};
	if (pointInRect(bat, midBottom)) {
		ball.speedy = -ball.speedy;
	}

}



void drawGame(sf::RenderWindow& window, Bat bat, Ball ball, const Textobj& text) {
	window.clear();
	window.draw(bat.shape);
	window.draw(ball.shape);
	textDraw(window, text);
	window.display();

}
