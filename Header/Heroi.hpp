#ifndef HEROI_HPP
#define HEROI_HPP

#include <SFML/Graphics.hpp>

class Heroi {
private:
    int munição;
    int maxMunição;
    int vida;
    int maxVida;
    int base;
    int maxBase;
    float velocidadeMovimento;
    bool movendo;
    sf::Vector2f posiçãoAlvo;
    sf::CircleShape sprite; 

public:
    Heroi();

    sf::CircleShape getCircle() const {
        return sprite;
    }

    void setVida(int novaVida, int dano);
    void setBase(int novaVida, int dano);
    void SetMunição(int novaMunição);
    int getVida() const;
    int getMaxVida() const;
    int getMunição() const;
    int getMaxMunição() const;
    int getBase() const;
    int getMaxBase() const;
    bool isMovendo() const;
    sf::Vector2f getPosição() const;
    void setPosição(const sf::Vector2f& posição);
    void mover(const sf::Vector2f& deslocamento);
    void atualizar(sf::RenderWindow& janela, sf::Event& evento);
};

#endif 