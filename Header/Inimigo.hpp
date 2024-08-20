#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Inimigo {
public:
    Inimigo(const sf::Vector2f& posicaoInicial, const sf::Vector2f& direcao, float velocidade);
    void atualizar(const sf::Vector2f& playerPosition);
    void desenhar(sf::RenderWindow& janela) const;
    
    // Método para acessar o corpo do inimigo
    const sf::CircleShape& getCorpo() const;

    static sf::Vector2f gerarPosicaoAleatoriaNaBorda(const sf::Vector2u& tamanhoJanela);

private:
    sf::CircleShape corpo;
    sf::Vector2f direcao;
    float velocidade;
};

#endif
