#include <SFML/Graphics.hpp>
 
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Base Defense");
    sf::Event ev;
 
    sf::RectangleShape fundo;
    fundo.setSize(sf::Vector2f(800, 600));
    fundo.setFillColor(sf::Color::White);
    fundo.setPosition(0, 0);
    
    sf::RectangleShape base;
    base.setSize(sf::Vector2f(300, 200));
    base.setFillColor(sf::Color::Green);
    base.setPosition(250, 200);

    sf::RectangleShape base2;
    base2.setSize(sf::Vector2f(280, 180));
    base2.setFillColor(sf::Color::White);
    base2.setPosition(260, 210);
 
    while(window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            if(ev.type == sf::Event::Closed)
                window.close();
        }
 
        window.clear();
        window.draw(fundo);
        window.draw(base);
        window.draw(base2);
        window.display();
    }
 
    return 0;
}