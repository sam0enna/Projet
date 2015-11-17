
#---------------------------------------------------------
# Variables
#---------------------------------------------------------
# Flags utilisés
CC = @ gcc
CXX = @ g++
FLAGS = -std=c++0x
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Liste de tous les objets du projet
OBJETS = TileMap Entite Etoile Joueur ScreenManager ScreenState Menu Bloc Decorator Neutre Cassable Game
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

Etoile:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	

Joueur:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	

ScreenManager:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c
		
ScreenState:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c

Menu:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c

Bloc:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c
	
Decorator:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c
	
Neutre:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c

Cassable:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c
	
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
