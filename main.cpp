#include <SFML/Graphics.hpp>
#include "Header/Heroi.hpp"
#include "Header/Icone.hpp"
#include "Header/Texto.hpp"
#include "Header/Projetil.hpp"
#include "Header/Inimigo.hpp"
#include "Header/Colide.hpp"
#include "Header/Som.hpp"
#include "Header/Fim.hpp"
#include <iostream>
#include <vector>
#include <chrono>

int main() {
    Heroi heroi;

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Base Defense");
    janela.setFramerateLimit(60);

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

    Icone VidaIcone("Media/Images/hearts.png", sf::Vector2f(728, 6), sf::Vector2f(0.04f, 0.04f), true);
    Icone MunicaoIcone("Media/Images/bullet.png", sf::Vector2f(734, 30), sf::Vector2f(0.8f, 0.8f), false);
    Icone BaseIcone("Media/Images/Home.png", sf::Vector2f(724, 55), sf::Vector2f(0.15f, 0.15f), false);
    Icone KillIcone("Media/Images/Kill.png", sf::Vector2f(728, 85), sf::Vector2f(0.04f, 0.04f), false);

    Texto textoVida("Media/Font/ARIAL.TTF", "100", 20, sf::Color::Red, sf::Vector2f(753, 3));
    Texto textoMunicao("Media/Font/ARIAL.TTF", "100", 20, sf::Color(74, 54, 30), sf::Vector2f(753, 30));
    Texto textoBase("Media/Font/ARIAL.TTF", "100", 20, sf::Color(0, 30, 0), sf::Vector2f(753, 57));
    Texto textoKill("Media/Font/ARIAL.TTF", "0", 20, sf::Color(0, 30, 0), sf::Vector2f(765, 82));
    
    Som Drop("Media/Sound/Life.flac");
    Som Kill("Media/Sound/Kill.wav");
    Som Defeat("Media/Sound/game_over.wav");

    std::vector<Projetil> projéteis;
    std::vector<Inimigo> inimigos;
    std::vector<Icone> icones;
    sf::Event evento;

    auto lastAddTime = std::chrono::steady_clock::now();
    std::chrono::milliseconds intervalo(2000); 

    int vidaBase = 100;
    int inimigosDestruídos = 0;

    sf::Font font;
    if (!font.loadFromFile("Media/Font/WHAPER.ttf")) {
        std::cerr << "Erro ao carregar a fonte." << std::endl;
        return -1;
    }

    Fim fimJogo(inimigosDestruídos, font);

    bool jogoAtivo = true;
    bool fimDeJogo = false;
    bool reiniciandoJogo = false;
    std::chrono::steady_clock::time_point fimJogoTempo;

    while (janela.isOpen()) {
        while (janela.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                janela.close();

            if (jogoAtivo) {
                if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Q) {
                    Projetil::dispararProjétil(heroi, janela, projéteis);
                } else if (vidaBase <= 0 || heroi.getVida() <= 0) {
                    jogoAtivo = false;
                    fimDeJogo = true;
                    fimJogoTempo = std::chrono::steady_clock::now();
                    Defeat.tocar();
                }
            } else if (fimDeJogo && evento.type == sf::Event::KeyPressed) {
                // Reinicie as variáveis do jogo
                vidaBase = 100;
                heroi.setVida(100, 0);
                heroi.SetMunição(100);
                inimigosDestruídos = 0;
                projéteis.clear();
                inimigos.clear();
                icones.clear();
                lastAddTime = std::chrono::steady_clock::now(); // Reinicia o temporizador de inimigos
                fimDeJogo = false;
                jogoAtivo = true;
                reiniciandoJogo = false;
            }
        }

        janela.clear();
        janela.draw(fundo);
        janela.draw(base);
        janela.draw(base2);

        if (jogoAtivo) {
            auto now = std::chrono::steady_clock::now();
            if (now - lastAddTime >= intervalo) {
                lastAddTime = now;

                sf::Vector2f posicaoInicial = Inimigo::gerarInimigo(janela.getSize());
                sf::Vector2f direcao(0.0f, 0.0f); // Ajustada na atualização
                float velocidade = 0.5f;

                inimigos.push_back(Inimigo(posicaoInicial, direcao, velocidade));
            }

            heroi.atualizar(janela, evento);

            for (auto it = projéteis.begin(); it != projéteis.end(); ) {
                it->atualizar();
                if (it->fora_da_janela(janela)) {
                    it = projéteis.erase(it);
                } else {
                    ++it;
                }
            }

            textoVida.setString(std::to_string(heroi.getVida()));
            textoMunicao.setString(std::to_string(heroi.getMunição()));
            textoBase.setString(std::to_string(vidaBase));
            textoKill.setString(std::to_string(inimigosDestruídos));

            VidaIcone.draw(janela);
            textoVida.draw(janela);
            MunicaoIcone.draw(janela);
            textoMunicao.draw(janela);
            BaseIcone.draw(janela);
            textoBase.draw(janela);
            KillIcone.draw(janela);
            textoKill.draw(janela);

            janela.draw(heroi.getCircle());

            for (auto it = inimigos.begin(); it != inimigos.end(); ) {
                it->atualizar(heroi.getPosição());
                
                bool removido = false;

                // Verificar colisão com a base
                if (colide(it->getCorpo(), base)) {
                    vidaBase -= 10;
                    removido = true;
                }

                // Verificar colisão com o herói
                if (colide(it->getCorpo(), heroi.getCircle())) {
                    heroi.setVida(heroi.getVida(), 10);
                    removido = true;
                }

                // Verificar colisão com projéteis
                for (auto jt = projéteis.begin(); jt != projéteis.end(); ) {
                    if (colide(it->getCorpo(), jt->getForma())) {
                        removido = true;
                        jt = projéteis.erase(jt);
                        inimigosDestruídos++;
                    } else {
                        ++jt;
                    }
                }

                if (removido) {
                    it->destruirInimigo(icones);
                    it = inimigos.erase(it);
                    Kill.tocar();
                } else {
                    it->desenhar(janela);
                    ++it;
                }
            }

            for (auto& inimigo : inimigos) {
                inimigo.dispararProjétil(heroi.getPosição());
                inimigo.atualizarProjeteis(janela, heroi, base, vidaBase);
            }

            for (const auto& projétil : projéteis) {
                projétil.desenhar(janela);
            }

            for (auto it = icones.begin(); it != icones.end(); ) {
                it->draw(janela);

                sf::FloatRect spriteBounds = it->getSprite().getGlobalBounds();
                sf::RectangleShape spriteShape(sf::Vector2f(spriteBounds.width, spriteBounds.height));
                spriteShape.setPosition(spriteBounds.left, spriteBounds.top);

                if (colide(heroi.getCircle(), spriteShape)) {
                    if (it->isLifeIcon()) {
                        heroi.setVida(heroi.getVida() + 10, 0);
                    } else if (it->isAmmoIcon()) {
                        heroi.SetMunição(heroi.getMunição() + 10);
                    }
                    
                    it = icones.erase(it);
                    Drop.tocar();
                } else {
                    ++it;
                }
            }
        } else if (fimDeJogo) {
            fimJogo.atualizar(inimigosDestruídos);
            fimJogo.draw(janela);

            auto now = std::chrono::steady_clock::now();
            if (now - fimJogoTempo >= std::chrono::seconds(1)) {
                if (evento.type == sf::Event::KeyPressed) {
                    vidaBase = 100;
                    heroi.setVida(100, 0);
                    heroi.SetMunição(100);
                    inimigosDestruídos = 0;
                    projéteis.clear();
                    inimigos.clear();
                    icones.clear();
                    lastAddTime = std::chrono::steady_clock::now(); 
                    fimDeJogo = false;
                    jogoAtivo = true;
                }
            }
        }

        janela.display();
    }

    return 0;
}
