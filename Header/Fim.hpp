#ifndef FIM_HPP
#define FIM_HPP

#include <SFML/Graphics.hpp>
#include "Texto.hpp"

class Fim {
public:
    Fim(int inimigosDestruídos, sf::Font& fonte);

    Fim();

    void atualizar(int inimigosDestruídos);
    void draw(sf::RenderWindow& janela);

private:
    int inimigosDestruídos;
    sf::Font font;
    Texto textoFim;
};

#endif // FIM_HPP