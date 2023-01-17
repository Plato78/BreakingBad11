#pragma once
#include "SFML/Graphics.hpp"
const float width = 1600.f;
const float height = 900.f;
const std::string title = "SFML Simple Arcanoid P33122";
//ÁÈÒÀ
const float bat_width = 150.f;
const float bat_height = 15.f;
const float bat_offset = 50.f;
const sf::Color Bat_Color{ sf::Color::White };
const sf::Vector2f bat_start_pos{ (width - bat_width) / 2, height - bat_offset - bat_height };
const float bat_speed = 40.f;
//ØÀÐ
const int BALL_WIDTH = 20;
const float ballradius = 10.f;
const int BALL_HEIGHT = 20.f;
const float ball_offset = 20.f;
const sf::Color ballColor{ sf::Color::White };
const sf::Vector2f ball_start_pos{};
float ball_dx = 3.f;
float ball_dy = 3.f;
//текст
const int charSize = 48;
const float textOffset = 50.f;
const sf::Vector2f textStartPos{ width - textOffset,0.f };
//кирпичи
const int brick_width = 20.f;
const int brick_height = 20.f;
const float brick_offset = 50.f;
const sf::Color brickColor{ sf::Color::Yellow };
const sf::Vector2f brick_pos{ (width - brick_width) / 2, height - brick_offset - brick_height };