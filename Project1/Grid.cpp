#include "Grid.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Crée une grille avec le nombre de lignes et de colonnes spécifié
Grid::Grid(int numRows, int numCols) : rows(numRows), cols(numCols) {
    grid = vector<vector<Cell>>(rows, vector<Cell>(cols));
    initializeEmptyCells();
}

Grid::Grid(vector<vector<int>>& setup) : rows(setup.size()), cols(setup[0].size()) {
    // Crée une grille en fonction d'une configuration spécifiée
    grid = vector<vector<Cell>>(rows, vector<Cell>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Initialise les cellules avec les valeurs de la configuration
            grid[i][j].setValue(setup[i][j]);
        }
    }
}

void Grid::generateRandomCell() {
    if (!emptyCells.empty()) {
        //on genere un nombre aleatoire entre 0 et le nombre de cellules vides puis on recupere la cellule correspondante
        int randomIndex = rand() % emptyCells.size();
        int randRow = emptyCells[randomIndex].first;
        int randCol = emptyCells[randomIndex].second;


        int nbrInt = (rand() % 3 <= 1) ? 2 : 4;

        //on met la valeur dans la cellule et on la supprime de la liste des cellules vides
        grid[randRow][randCol].setValue(nbrInt);
        emptyCells.erase(emptyCells.begin() + randomIndex);

    }
}

// Met à jour la liste des cellules vides
void Grid::updateEmptyCells() {
    emptyCells.clear();  // Vide la liste actuelle
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j].isEmptyCell()) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }
}

// Réinitialise l'état de fusion des cellules
void Grid::updateMergedCells() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j].resetMerged();
        }
    }
}

// Affiche la grille à l'écran
void Grid::display() {
    
    for (int i = 0; i < cols * 7 + 1; ++i) {
        cout << "-";
    }
    cout << endl;

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "| ";
            int cellValue = grid[i][j].getValue();
            if (cellValue != 0) {
                if (cellValue < 10) {
                    cout << " " << cellValue << "  "; 
                }
                else if (cellValue < 100) {
                    cout << " " << cellValue << " ";
                }
                else if (cellValue < 1000) {
                    cout << cellValue << " ";
                }
            }
            else {
                cout << "    ";
            }
            cout << "|";
        }
        cout << endl;

        
        for (int k = 0; k < cols * 7 + 1; ++k) {
            cout << "-";
        }
        cout << endl;
    }
}

// Vérifie si le jeu est terminé (plus de mouvements possibles)
void Grid::checkGameOver() {
    
    if (emptyCells.empty()) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols - 1; j++) {
                if (grid[i][j].getValue() == grid[i][j + 1].getValue()) {
                    listGameover.push_back(0);
                }
                else {
                    listGameover.push_back(1);
                }
            }
        }

        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j].getValue() == grid[i + 1][j].getValue()) {
                    listGameover.push_back(0);
                }
                else {
                    listGameover.push_back(1);
                }
            }
        }
    }
}

// Vérifie si le jeu est terminé en se basant sur la vérification précédente
bool Grid::isGameOver() {
    checkGameOver();
    for (int i = 0; i < listGameover.size(); i++) {
        if (listGameover[i] == 0) {
			return false;
		}
	}
}

// Réinitialise la liste de vérification de fin du jeu
void Grid::clearCheckGameOver() {
	listGameover.clear();
}

// Initialise la liste des cellules vides avec leur position dans la grille
void Grid::initializeEmptyCells() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            emptyCells.push_back(make_pair(i, j));
        }
    }
}
