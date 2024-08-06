#include "../Header/Projetil.hpp"
#include <cmath>

Projetil::Projetil(const sf::Vector2f& posiçãoInicial, const sf::Vector2f& direção, float velocidade)
    : direção(direção), velocidade(velocidade) {
    forma.setRadius(3.0f);
    forma.setFillColor(sf::Color::Black);
    forma.setPosition(posiçãoInicial);
}

void Projetil::atualizar() {
    forma.move(direção * velocidade);
}

void Projetil::desenhar(sf::RenderWindow& janela) const {
    janela.draw(forma);
}

bool Projetil::fora_da_janela(const sf::RenderWindow& janela) const {
    sf::Vector2f posição = forma.getPosition();
    return (posição.x < 0 || posição.x > janela.getSize().x || posição.y < 0 || posição.y > janela.getSize().y);
}

void Projetil::dispararProjétil(Heroi& heroi, sf::RenderWindow& janela, std::vector<Projetil>& projéteis) {
    if (heroi.getMunição() > 0) {
        sf::Vector2f posiçãoHeroi = heroi.getPosição();
        sf::Vector2i posiçãoMouse = sf::Mouse::getPosition(janela);
        sf::Vector2f direçãoMouse = sf::Vector2f(static_cast<float>(posiçãoMouse.x), static_cast<float>(posiçãoMouse.y)) - posiçãoHeroi;
        float comprimento = std::sqrt(direçãoMouse.x * direçãoMouse.x + direçãoMouse.y * direçãoMouse.y);
        direçãoMouse /= comprimento; //constante
        projéteis.emplace_back(posiçãoHeroi, direçãoMouse, 5.0f); // Velocidade do projétil
        heroi.SetMunição();
    }
}
