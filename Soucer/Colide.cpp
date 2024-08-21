#include "../Header/Colide.hpp"
#include <cmath>

// Função para colisão entre dois círculos
bool colide(const sf::Shape& forma1, const sf::Shape& forma2) {
    // Tenta fazer o cast para sf::CircleShape
    const sf::CircleShape* circulo1 = dynamic_cast<const sf::CircleShape*>(&forma1);
    const sf::CircleShape* circulo2 = dynamic_cast<const sf::CircleShape*>(&forma2);

    if (circulo1 && circulo2) {
        // Colisão entre dois círculos
        sf::Vector2f pos1 = circulo1->getPosition();
        sf::Vector2f pos2 = circulo2->getPosition();
        float raio1 = circulo1->getRadius();
        float raio2 = circulo2->getRadius();

        float distancia = std::sqrt((pos2.x - pos1.x) * (pos2.x - pos1.x) + (pos2.y - pos1.y) * (pos2.y - pos1.y));
        return distancia < (raio1 + raio2);
    }

    // Se as formas não forem círculos, utiliza interseção dos bounds
    return forma1.getGlobalBounds().intersects(forma2.getGlobalBounds());
}

// Função para colisão entre um círculo e um retângulo
bool colide(const sf::CircleShape& circulo, const sf::RectangleShape& retangulo) {
    sf::Vector2f circuloPos = circulo.getPosition();
    float raio = circulo.getRadius();

    sf::FloatRect retanguloBounds = retangulo.getGlobalBounds();
    sf::Vector2f retanguloCentro(retanguloBounds.left + retanguloBounds.width / 2.0f, retanguloBounds.top + retanguloBounds.height / 2.0f);

    float distanciaX = std::max(retanguloBounds.left, std::min(circuloPos.x, retanguloBounds.left + retanguloBounds.width));
    float distanciaY = std::max(retanguloBounds.top, std::min(circuloPos.y, retanguloBounds.top + retanguloBounds.height));

    float distancia = std::sqrt((distanciaX - circuloPos.x) * (distanciaX - circuloPos.x) + (distanciaY - circuloPos.y) * (distanciaY - circuloPos.y));

    return distancia < raio;
}
