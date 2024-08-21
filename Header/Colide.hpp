#ifndef COLIDE_HPP
#define COLIDE_HPP

#include <SFML/Graphics.hpp>

bool colide(const sf::CircleShape& circulo, const sf::RectangleShape& retangulo);
bool colide(const sf::Shape& forma1, const sf::Shape& forma2);

#endif
