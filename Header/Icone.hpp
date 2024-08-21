#ifndef ICONE_HPP
#define ICONE_HPP

#include <SFML/Graphics.hpp>
#include "Heroi.hpp"

class Icone {
private:
    sf::Texture textura;
    sf::Sprite sprite;
    bool isLife;  // true para vida, false para munição

public:
    Icone(const std::string& caminhoTextura, sf::Vector2f posicao, sf::Vector2f escala, bool isLife);

    void draw(sf::RenderWindow& window);
    sf::Sprite getSprite() const;
    bool isLifeIcon() const { return isLife; }
    bool isAmmoIcon() const { return !isLife; }
    void verificarColisoes(std::vector<Icone>& icones, Heroi& heroi);
};

#endif

