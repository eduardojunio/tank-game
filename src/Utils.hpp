#ifndef TANKGAME_UTILS_HPP
#define TANKGAME_UTILS_HPP

#include <vector>
#include <SFML/Graphics.hpp>

constexpr int WINDOW_WIDTH = 1400; // 35 * (8 * 5)
constexpr int WINDOW_HEIGHT = 1000; // 25 * (8 * 5)

std::vector<sf::FloatRect> loadMap();

#endif//TANKGAME_UTILS_HPP
