#ifndef SOM_HPP
#define SOM_HPP

#include <SFML/Audio.hpp>
#include <string>

class Som {
public:
    // Construtor que carrega um arquivo de som
    Som(const std::string& arquivo);
    
    // Função para tocar o som
    void tocar();

    // Função para parar o som
    void parar();

private:
    sf::SoundBuffer buffer;  // Buffer para armazenar os dados do som
    sf::Sound som;           // Objeto de som para reproduzir o som
};

#endif // SOM_HPP
