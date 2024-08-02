#include "../Header/Texto.hpp"

Texto::Texto(const std::string& caminhoFonte, const std::string& conteudo, unsigned int tamanho, sf::Color cor, sf::Vector2f posicao) {
    if (!fonte.loadFromFile(caminhoFonte)) {
        // Handle error
    }
    texto.setFont(fonte);
    texto.setString(conteudo);
    texto.setCharacterSize(tamanho);
    texto.setFillColor(cor);
    texto.setPosition(posicao);
}

void Texto::setString(const std::string& conteudo) {
    texto.setString(conteudo);
}

void Texto::draw(sf::RenderWindow& window) {
    window.draw(texto);
}
