#include "../Header/Fim.hpp"
#include "../Header/Texto.hpp"
#include "../Header/Som.hpp"

Fim::Fim(int inimigosDestruídos, sf::Font& fonte)
    : inimigosDestruídos(inimigosDestruídos), font(fonte), textoFim("Media/Font/WHAPER.ttf", "Kills ", 60, sf::Color::Red, sf::Vector2f(325, 265)) {
}

void Fim::atualizar(int inimigosDestruídos) {
    this->inimigosDestruídos = inimigosDestruídos;
    textoFim.setString(std::to_string(inimigosDestruídos) + " Kills");
}

void Fim::draw(sf::RenderWindow& janela) {
    textoFim.draw(janela);
}
