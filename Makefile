
#---------------------------------------------------------
# Variables
#---------------------------------------------------------
# Flags utilisés
CC = @ gcc
CXX = @ g++
FLAGS = -std=c++0x
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
# Liste de tous les objets du projet
OBJETS = TileMap Entite Joueur ScreenManager ScreenState Menu Game
DEPENDANCES = $(foreach file, $(OBJETS), build/$(file).o)

#---------------------------------------------------------
# Compilation complète du projet & exécution
#---------------------------------------------------------
all: prepare Main

exec:
	./main
#---------------------------------------------------------
# Création du dossier de build
#---------------------------------------------------------
prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

#---------------------------------------------------------
# Compilations individuelles des différentes classes du projet
#---------------------------------------------------------	
TileMap:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c	

Entite:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	

Joueur:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	

ScreenManager:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c
		
ScreenState:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c

Menu:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c

Game:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c

Main: $(OBJETS) 
	$(CXX) $(FLAGS) src/$@.cpp $(DEPENDANCES) $(SFMLFLAGS) -o main
	@clear
	@ ./main
	
	
#---------------------------------------------------------
# Nettoyage du dossier de build
#---------------------------------------------------------
clean:
	@rm -rf ./build
