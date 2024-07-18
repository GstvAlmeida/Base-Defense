#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include "hero.hpp"
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
    
    // texturas para vida e munição
    sf::Texture texturaVida;
    sf::Texture texturaMunicao;

    if (!texturaVida.loadFromFile("Media/Images/heart.png")) { // Carregar textura
        std::cerr << "Erro ao carregar a textura de vida" << std::endl;
        return -1;
    }

    if (!texturaMunicao.loadFromFile("Media/Images/bullet.png")) { // Carregar textura
        std::cerr << "Erro ao carregar a textura de munição" << std::endl;
        return -1;
    }

    // ícones vida e munição
    sf::Sprite vidaIcone;
    sf::Sprite municaoIcone;

    vidaIcone.setTexture(texturaVida);
    municaoIcone.setTexture(texturaMunicao);

    // Ajustar tamanhos e posições
    vidaIcone.setScale(1.0f, 1.0f); // escala
    vidaIcone.setPosition(730 - vidaIcone.getGlobalBounds().width - 5, 7);

    municaoIcone.setScale(0.02f, 0.02f);
    municaoIcone.setPosition(718 - municaoIcone.getGlobalBounds().width - 5, 30);

    sf::Font fonte;
    if (!fonte.loadFromFile("Font/ARIAL.TTF")) {
        return -1; // Erro ao carregar a fonte
    }

    sf::Text textoVida;
    textoVida.setFont(fonte);
    textoVida.setCharacterSize(20);
    textoVida.setFillColor(sf::Color::Red);

    sf::Text textoMunicao;
    textoMunicao.setFont(fonte);
    textoMunicao.setCharacterSize(20);
    textoMunicao.setFillColor(sf::Color::Black);

    textoVida.setPosition(730 - textoVida.getLocalBounds().width - 10, 10);
    textoMunicao.setPosition(730 - textoMunicao.getLocalBounds().width - 10, 30);

    sf::Event evento;
    while (janela.isOpen()) {
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                janela.close();
        }

        // Atualizar o herói
        heroi.atualizar(janela, evento);

        // Atualizar textos
        textoVida.setString(std::to_string(heroi.getVida()) + "/" + std::to_string(heroi.getMaxVida()));
        textoMunicao.setString(std::to_string(heroi.getMunição()) + "/" + std::to_string(heroi.getMaxMunição()));

        janela.clear();
        janela.draw(fundo);
        janela.draw(base);
        janela.draw(base2);

        // Desenhar os ícones e textos no canto superior direito
        janela.draw(vidaIcone);
        janela.draw(textoVida);

        janela.draw(municaoIcone);
        janela.draw(textoMunicao);

        janela.draw(heroi.getCircle());
        janela.display();
    }

    return 0;
}
