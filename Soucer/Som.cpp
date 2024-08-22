#include "../Header/Som.hpp"

// Construtor de arquivo de som
Som::Som(const std::string& arquivo) {
    if (!buffer.loadFromFile(arquivo)) {
        // Lidar com erro
        throw std::runtime_error("Não foi possível carregar o arquivo de som.");
    }
    som.setBuffer(buffer);
}

void Som::tocar() {
    som.play();
}

void Som::parar() {
    som.stop();
}