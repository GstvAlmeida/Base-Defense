#include "../Header/Icone.hpp"
#include <iostream>

Icone::Icone(const std::string& caminhoTextura, sf::Vector2f posicao, sf::Vector2f escala, bool isLife)
    : isLife(isLife) {
    if (!textura.loadFromFile(caminhoTextura)) {
        std::cout << caminhoTextura << "Não encontrado"; // Error
    }
    sprite.setTexture(textura);
    sprite.setPosition(posicao);
    sprite.setScale(escala);
}

void Icone::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::Sprite Icone::getSprite() const {
    return sprite;
}
