g++: main.cpp
	g++ main.cpp Soucer/Projetil.cpp Soucer/Heroi.cpp Soucer/Icone.cpp  Soucer/Texto.cpp -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -o main && ./main
