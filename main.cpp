#include <SFML/Graphics.hpp>
#include "Header/Heroi.hpp"
#include "Header/Icone.hpp"
#include "Header/Texto.hpp"
#include "Header/Projetil.hpp"
#include <iostream>
#include <vector>

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
    Icone VidaIcone("Media/Images/heart.png", sf::Vector2f(723, 3), sf::Vector2f(1.0f, 1.0f));
    Icone MunicaoIcone("Media/Images/bullet.png", sf::Vector2f(734, 30), sf::Vector2f(0.8f, 0.8f));
    Icone BaseIcone("Media/Images/Home.png", sf::Vector2f(724, 55), sf::Vector2f(0.15f, 0.15f));

    Texto textoVida("Media/Font/ARIAL.TTF", "100", 20, sf::Color::Red, sf::Vector2f(753, 6));
    Texto textoMunicao("Media/Font/ARIAL.TTF", "50", 20, sf::Color(74, 54, 30), sf::Vector2f(753, 30));
    Texto textoBase("Media/Font/ARIAL.TTF", "50", 20, sf::Color(0, 30, 0), sf::Vector2f(753, 57));

    std::vector<Projetil> projéteis;
    sf::Event evento;

    while (janela.isOpen()) {
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                janela.close();

            if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Q) {
                Projetil::dispararProjétil(heroi, janela, projéteis);
            }
        }

        // Atualizar o herói
        heroi.atualizar(janela, evento);

        // Atualizar projéteis
        for (auto it = projéteis.begin(); it != projéteis.end(); ) {
            it->atualizar();
            if (it->fora_da_janela(janela)) {
                it = projéteis.erase(it);
            } else {
                ++it;
            }
        }

        // Atualizar textos
        textoVida.setString(std::to_string(heroi.getVida()));
        textoMunicao.setString(std::to_string(heroi.getMunição()));
        textoBase.setString(std::to_string(heroi.getBase()));

        janela.clear();
        janela.draw(fundo);
        janela.draw(base);
        janela.draw(base2);

        // Desenhar os ícones e textos no canto superior direito
        VidaIcone.draw(janela);
        textoVida.draw(janela);
        MunicaoIcone.draw(janela);
        textoMunicao.draw(janela);
        BaseIcone.draw(janela);
        textoBase.draw(janela);

        // Desenhar o herói
        janela.draw(heroi.getCircle());

        // Desenhar projéteis
        for (const auto& projetil : projéteis) {
            projetil.desenhar(janela);
        }

        janela.display();
    }

    return 0;
}