#ifndef PROJETIL_HPP
#define PROJETIL_HPP

#include <SFML/Graphics.hpp>
#include "Heroi.hpp"
#include <vector>

class Projetil {
private:
    sf::CircleShape forma;
    sf::Vector2f direção;
    float velocidade;
    int mun;

public:
    Projetil(const sf::Vector2f& posiçãoInicial, const sf::Vector2f& direção, float velocidade);
    void atualizar();
    void desenhar(sf::RenderWindow& janela) const;
    bool fora_da_janela(const sf::RenderWindow& janela) const;
    static void dispararProjétil(Heroi& heroi, sf::RenderWindow& janela, std::vector<Projetil>& projéteis);
    sf::CircleShape getForma() const; 
    int setMun(int mun);
};

#endif
