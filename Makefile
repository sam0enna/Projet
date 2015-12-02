
#---------------------------------------------------------
# Variables
#---------------------------------------------------------
# Flags utilisés
CC = @ gcc
CXX = @ g++
FLAGS = -std=c++0x
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
# Liste de tous les objets du projet
OBJETS = TileMap Entite Monstre Etoile Champignon Joueur ActionBonus BonusVie MalusVie VieNeutre BonusChamp ScreenManager ScreenState Menu Bloc Decorator Neutre Cassable Exit Game Fin
DEPENDANCES = $(foreach file, $(OBJETS), build/$(file).o)

#---------------------------------------------------------
# Compilation complète du projet & exécution
#---------------------------------------------------------
all: prepare Main

exec:
	export LD_LIBRARY_PATH=SFML-2.3.2/lib && ./main
#---------------------------------------------------------
# Création du dossier de build
#---------------------------------------------------------
prepare:
	@if [ ! -d ./build ] ; then mkdir ./build ; fi;

#---------------------------------------------------------
# Compilations individuelles des différentes classes du projet
#---------------------------------------------------------	
TileMap:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c	-I SFML-2.3.2/include

Entite:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include

Monstre:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include

Etoile:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 

Champignon:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 

Joueur:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 

ActionBonus:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 
	
BonusVie:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 
	
MalusVie:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 

VieNeutre:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 

BonusChamp:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Entite/$@.cpp -c	-I SFML-2.3.2/include 


ScreenManager:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c -I SFML-2.3.2/include
		
ScreenState:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c -I SFML-2.3.2/include 

Menu:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c -I SFML-2.3.2/include 

Bloc:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c -I SFML-2.3.2/include
	
Decorator:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c -I SFML-2.3.2/include 
	
Neutre:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c -I SFML-2.3.2/include 

Cassable:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c -I SFML-2.3.2/include 
	
Exit:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Bloc/$@.cpp -c -I SFML-2.3.2/include 
	
Game:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c -I SFML-2.3.2/include 

	
Fin:
	$(CXX) $(FLAGS) $(SFMLFLAGS) -o build/$@.o src/Screen/$@.cpp -c -I SFML-2.3.2/include 

Main: $(OBJETS) 
	$(CXX) $(FLAGS) src/$@.cpp $(DEPENDANCES) $(SFMLFLAGS) -o main -I SFML-2.3.2/include -L SFML-2.3.2/lib
	@clear
	@ export LD_LIBRARY_PATH=SFML-2.3.2/lib && ./main
	
	
#---------------------------------------------------------
# Nettoyage du dossier de build
#---------------------------------------------------------
clean:
	@rm -rf ./build
