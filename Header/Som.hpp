#ifndef SOM_HPP
#define SOM_HPP

#include <SFML/Audio.hpp>
#include <string>

class Som {
public:
    Som(const std::string& arquivo);
    
    void tocar();

    void parar();

private:
    sf::SoundBuffer buffer;  
    sf::Sound som;           
};

#endif // SOM_HPP