
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>
#include "Move.h"
//#include "Test.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;


int main() {
	int rows = 4;
	int cols = 4;

	srand(time(0));

	Grid grid(rows, cols);  // Crée la grille du jeu 2048
	Move move;
	//Test test;

	// Remplit la grille avec deux cellules aléatoires au début
	for (int count = 0; count < 2; count++) {
		grid.generateRandomCell();
	}
	
	grid.display();

	// Teste les mouvements (gauche, droite, haut, bas)
	/*test.gridLeft();
	test.gridRight();
	test.gridUp();
	test.gridDown();*/

	while (true) {
		int choix;
		bool badKey = true;
		system("cls");

		// Si un mouvement a eu lieu, met à jour les data de la grille
		if (move.moved == true) {
			grid.updateMergedCells();
			grid.updateEmptyCells();
			grid.generateRandomCell();
			grid.clearCheckGameOver();
			move.moved = false;
		}
		grid.display();
		cout << " < Gauche | >  Droite | ^  Haut | v  Bas " << endl;
		switch ((choix = _getch())) {
			case KEY_UP:
				move.moveUp(grid);
				break;
			case KEY_DOWN:
				move.moveDown(grid);
				break;
			case KEY_RIGHT:
				move.moveRight(grid);
				break;
			case KEY_LEFT:
				move.moveLeft(grid);
				break;
			default:
				cout << "Choix invalide" << endl;
				badKey = true;
				break;
		}

		// Vérifie si le jeu est terminé
		if (grid.isGameOver()) {
			cout << "Game Over" << endl;
			break;
		}
	}

	cout << "Fin du jeu" << endl;
	cout << "Voulez-vous rejouer ?" << endl;
	cout << "1 Oui | 2 Non" << endl;
	int replay;
	cin >> replay;
	if (replay == 1) {
		main(); // Redémarre le jeu si le joueur le souhaite
	}
	else {
		cout << "Au revoir" << endl;
	}

	return 0;
};