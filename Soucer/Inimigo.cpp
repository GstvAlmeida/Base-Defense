#include "../Header/Inimigo.hpp"
#include "../Header/Projetil.hpp"
#include "../Header/Heroi.hpp"
#include "../Header/Colide.hpp"
#include <cmath>
#include <random>
#include <chrono>

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

void Inimigo::dispararProjétil(const sf::Vector2f& posicaoHeroi) {
    auto agora = std::chrono::steady_clock::now();
    if (std::chrono::duration_cast<std::chrono::seconds>(agora - ultimoDisparo).count() >= 2) {
        sf::Vector2f direção = posicaoHeroi - corpo.getPosition();
        float comprimento = std::sqrt(direção.x * direção.x + direção.y * direção.y);
        direção /= comprimento;
        projéteisInimigos.emplace_back(corpo.getPosition(), direção, 5.0f);
        ultimoDisparo = agora;
    }
}

void Inimigo::atualizarProjeteis(sf::RenderWindow& janela, Heroi& heroi, sf::RectangleShape& base, int& vidaBase) {
    for (auto it = projéteisInimigos.begin(); it != projéteisInimigos.end(); ) {
        it->atualizar();

        // Verifica colisão com o herói
        if (colide(it->getForma(), heroi.getCircle())) {
            heroi.setVida(heroi.getVida(), 10);
            it = projéteisInimigos.erase(it);
        }
        // Verifica colisão com a base
        else if (colide(it->getForma(), base)) {
            vidaBase -= 10;
            it = projéteisInimigos.erase(it);
        }
        // Verifica se o projétil saiu da janela
        else if (it->fora_da_janela(janela)) {
            it = projéteisInimigos.erase(it);
        } 
        else {
            it->desenhar(janela);
            ++it;
        }
    }
}