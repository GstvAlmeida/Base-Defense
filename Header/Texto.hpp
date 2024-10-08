#ifndef TEXTO_HPP
#define TEXTO_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Texto {
public:
    Texto(const std::string& caminhoFonte, const std::string& conteudo, unsigned int tamanho, sf::Color cor, sf::Vector2f posicao);
    
    void setString(const std::string& conteudo);
    void draw(sf::RenderWindow& window);

private:
    sf::Font fonte;
    sf::Text texto;
};

#endif // TEXTO_HPP