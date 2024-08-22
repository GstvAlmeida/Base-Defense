#include <SFML/Graphics.hpp>
#include <cmath>
#include "../Header/Heroi.hpp"

Heroi::Heroi()
    : munição(100), maxMunição(100), vida(100), maxVida(100), base(100), maxBase(100), velocidadeMovimento(4.0f), movendo(false) {
    sprite.setRadius(5.0f); // Raio do círculo do herói
    sprite.setFillColor(sf::Color(230, 230, 230)); // Cor do círculo do herói
    sprite.setOutlineThickness(1.0f); // Espessura do contorno
    sprite.setOutlineColor(sf::Color::Black); // Cor do contorno
    sprite.setPosition(395, 295); // Posição inicial do herói
    posiçãoAlvo = sprite.getPosition();
}

void Heroi::setVida(int novaVida, int dano) {
    if (novaVida - dano < 0) {
        this->vida = 0;
    } else if ((novaVida - dano) > 100){  
        this->vida = 100;
    } else {
        this->vida = novaVida - dano;
    };
}

void Heroi::setBase(int novaBase, int dano) {
    if (novaBase - dano < 0) {
        this->base = 0;
    } else {
        this->base = novaBase - dano;
    };
}

void Heroi::SetMunição(int novaMunição) {
    this->munição = novaMunição;
}

int Heroi::getVida() const {
    return vida;
}

int Heroi::getMaxVida() const {
    return maxVida;
}

int Heroi::getMunição() const {
    return munição;
}

int Heroi::getMaxMunição() const {
    return maxMunição;
}

int Heroi::getBase() const {
    return base;
}

bool Heroi::isMovendo() const {
    return movendo;
}

sf::Vector2f Heroi::getPosição() const {
    return sprite.getPosition();
}

void Heroi::setPosição(const sf::Vector2f& posição) {
    sprite.setPosition(posição);
}

void Heroi::mover(const sf::Vector2f& deslocamento) {
    sprite.move(deslocamento);
}

void Heroi::atualizar(sf::RenderWindow& janela, sf::Event& evento) {
    if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Right) {
        sf::Vector2i posiçãoMouse = sf::Mouse::getPosition(janela);
        posiçãoAlvo = sf::Vector2f(static_cast<float>(posiçãoMouse.x), static_cast<float>(posiçãoMouse.y));
        movendo = true;
    }
    
    if (movendo) {
        sf::Vector2f direção = posiçãoAlvo - sprite.getPosition();
        float distância = std::sqrt(direção.x * direção.x + direção.y * direção.y);
        if (distância > velocidadeMovimento) {
            direção /= distância;
            direção *= velocidadeMovimento;
            mover(direção);
        } else {
            setPosição(posiçãoAlvo);
            movendo = false;
        }
    }
}