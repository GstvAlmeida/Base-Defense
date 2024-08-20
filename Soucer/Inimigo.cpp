#include "../Header/Inimigo.hpp"
#include <cmath>
#include <random>

Inimigo::Inimigo(const sf::Vector2f& posicaoInicial, const sf::Vector2f& direcao, float velocidade)
    : direcao(direcao), velocidade(velocidade) {
    corpo.setRadius(7.0f);
    corpo.setFillColor(sf::Color::Red);
    corpo.setPosition(posicaoInicial);
}

void Inimigo::atualizar(const sf::Vector2f& playerPosition) {
    sf::Vector2f direction = playerPosition - corpo.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {
        direction /= length;
    }
    corpo.move(direction * velocidade);
}

void Inimigo::desenhar(sf::RenderWindow& janela) const {
    janela.draw(corpo);
}

sf::Vector2f Inimigo::gerarPosicaoAleatoriaNaBorda(const sf::Vector2u& tamanhoJanela) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0, 1);

    float randPos = dis(gen);
    sf::Vector2f posicao;

    if (randPos < 0.25f) {
        posicao.x = dis(gen) * tamanhoJanela.x;
        posicao.y = 0;
    } else if (randPos < 0.5f) {
        posicao.x = tamanhoJanela.x;
        posicao.y = dis(gen) * tamanhoJanela.y;
    } else if (randPos < 0.75f) {
        posicao.x = dis(gen) * tamanhoJanela.x;
        posicao.y = tamanhoJanela.y;
    } else {
        posicao.x = 0;
        posicao.y = dis(gen) * tamanhoJanela.y;
    }

    return posicao;
}

// Implementação do método getter
const sf::CircleShape& Inimigo::getCorpo() const {
    return corpo;
}
