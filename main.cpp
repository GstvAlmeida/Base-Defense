#include <SFML/Graphics.hpp>
#include "Header/hero.hpp"
#include "Header/Icone.hpp"
#include "Header/Texto.hpp"
#include <iostream>

int main() {
    // Criar herói
    Heroi heroi;

    // Criar janela
    sf::RenderWindow janela(sf::VideoMode(800, 600), "Base Defense");
    janela.setFramerateLimit(60);

    // Criar fundo e a base
    sf::RectangleShape fundo;
    fundo.setSize(sf::Vector2f(800, 600));
    fundo.setFillColor(sf::Color::White);
    
    sf::RectangleShape base;
    base.setSize(sf::Vector2f(300, 200));
    base.setFillColor(sf::Color::Green);
    base.setPosition(250, 200);

    sf::RectangleShape base2;
    base2.setSize(sf::Vector2f(280, 180));
    base2.setFillColor(sf::Color::White);
    base2.setPosition(260, 210);

    // Criar ícones e textos
    Icone VidaIcone("Media/Images/heart.png", sf::Vector2f(720, 4), sf::Vector2f(1.0f, 1.0f));
    Icone municaoIcone("Media/Images/bullet.png", sf::Vector2f(730, 30), sf::Vector2f(0.02f, 0.02f));

    Texto textoVida("Font/ARIAL.TTF", "100", 20, sf::Color::Red, sf::Vector2f(750, 7));
    Texto textoMunicao("Font/ARIAL.TTF", "50", 20, sf::Color::Blue, sf::Vector2f(750, 30));

    sf::Event evento;
    while (janela.isOpen()) {
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                janela.close();
        }

        // Atualizar o herói
        heroi.atualizar(janela, evento);

        // Atualizar textos
        textoVida.setString(std::to_string(heroi.getVida()));
        textoMunicao.setString(std::to_string(heroi.getMunição()));

        janela.clear();
        janela.draw(fundo);
        janela.draw(base);
        janela.draw(base2);

        // Desenhar os ícones e textos no canto superior direito
        VidaIcone.draw(janela);
        textoVida.draw(janela);
        municaoIcone.draw(janela);
        textoMunicao.draw(janela);

        janela.draw(heroi.getCircle());
        janela.display();
    }

    return 0;
}
