#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <SFML/Graphics.hpp>
#include "Heroi.hpp"
#include "Projetil.hpp"
#include "Icone.hpp"
#include <vector>
#include <chrono>

class Inimigo {
public:
    Inimigo(const sf::Vector2f& posicaoInicial, const sf::Vector2f& direcao, float velocidade);
    void atualizar(const sf::Vector2f& playerPosition);
    void desenhar(sf::RenderWindow& janela) const;
    void dispararProjétil(const sf::Vector2f& posicaoHeroi);
    void atualizarProjeteis(sf::RenderWindow& janela, Heroi& heroi, sf::RectangleShape& base, int& vidaBase);
    void destruirInimigo(std::vector<Icone>& icones);

    // Método para acessar o corpo do inimigo
    const sf::CircleShape& getCorpo() const;

    static sf::Vector2f gerarInimigo(const sf::Vector2u& tamanhoJanela);

private:
    sf::CircleShape corpo;
    sf::Vector2f direcao;
    float velocidade;
    std::vector<Projetil> projéteisInimigos;
    std::chrono::steady_clock::time_point ultimoDisparo;
};

#endif
