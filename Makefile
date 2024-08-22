CXX = g++

LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

SRC_FILES = main.cpp \
            Soucer/Projetil.cpp \
            Soucer/Heroi.cpp \
            Soucer/Icone.cpp \
            Soucer/Texto.cpp \
            Soucer/Inimigo.cpp \
            Soucer/Colide.cpp \
            Soucer/Som.cpp \
            Soucer/Fim.cpp

OBJ_FILES = main.o \
            Soucer/Projetil.o \
            Soucer/Heroi.o \
            Soucer/Icone.o \
            Soucer/Texto.o \
            Soucer/Inimigo.o \
            Soucer/Colide.o \
            Soucer/Som.o \
            Soucer/Fim.o

all: projeto

projeto: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(LIBS) -o projeto

%.o: %.cpp
	$(CXX) -c $< -o $@

run: projeto
	./projeto

dev: projeto
	./projeto

clean:
	rm -f $(OBJ_FILES) projeto
