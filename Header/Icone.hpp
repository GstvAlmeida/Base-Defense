#ifndef ICONE_HPP
#define ICONE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Icone {
public:
    Icone(const std::string& caminhoTextura, sf::Vector2f posicao, sf::Vector2f escala);

    void draw(sf::RenderWindow& window);

private:
    sf::Texture textura;
    sf::Sprite sprite;
};

#endif 
