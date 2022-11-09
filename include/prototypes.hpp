#pragma once

#include "libs.hpp"

void buildMainMenu();
void buildLevel1();

// Utility functions
sf::Vector2f getCenter(sf::Texture texture);
sf::Vector2f getCenter(float width, float height);
sf::Vector2f getCenter(sf::Shape &shape);
sf::Vector2f getCenter(sf::Text &shape);

sf::Vector2i getMousePosition(sf::RenderWindow* window);
bool DoMouseIntersect(sf::Vector2i mousePos, sf::FloatRect to_check);

int randomNumber(int min_num, int max_num);

// Button functions
void exempleFunc();
void buttonExitGameFunc();
void buttonPlayGameFunc();
void buttonBackMainMenuFunc();