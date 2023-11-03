#include "Data_Grid.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Cr�e une grille avec le nombre de lignes et de colonnes sp�cifi�
Data_Grid::Data_Grid(int numRows, int numCols) : rows(numRows), cols(numCols) {
    dataGrid = vector<vector<Cell>>(rows, vector<Cell>(cols));
    initializeEmptyCells();
}

Data_Grid::Data_Grid(vector<vector<int>>& setup) : rows(setup.size()), cols(setup[0].size()) {
    // Cr�e une grille en fonction d'une configuration sp�cifi�e
    dataGrid = vector<vector<Cell>>(rows, vector<Cell>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Initialise les cellules avec les valeurs de la configuration
            dataGrid[i][j].setValue(setup[i][j]);
        }
    }
}

void Data_Grid::generateRandomCell() {
    if (!emptyCells.empty()) {
        //on genere un nombre aleatoire entre 0 et le nombre de cellules vides puis on recupere la cellule correspondante
        int randomIndex = rand() % emptyCells.size();
        int randRow = emptyCells[randomIndex].first;
        int randCol = emptyCells[randomIndex].second;


        int nbrInt = (rand() % 3 <= 1) ? 2 : 4;

        //on met la valeur dans la cellule et on la supprime de la liste des cellules vides
        dataGrid[randRow][randCol].setValue(nbrInt);
        emptyCells.erase(emptyCells.begin() + randomIndex);

    }
}

// Met � jour la liste des cellules vides
void Data_Grid::updateEmptyCells() {
    emptyCells.clear();  // Vide la liste actuelle
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (dataGrid[i][j].isEmptyCell()) {
                emptyCells.push_back(make_pair(i, j));
            }
        }
    }
}

// R�initialise l'�tat de fusion des cellules
void Data_Grid::updateMergedCells() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dataGrid[i][j].resetMerged();
        }
    }
}

// Affiche la grille � l'�cran
void Data_Grid::display() {

    for (int i = 0; i < cols * 7 + 1; ++i) {
        cout << "-";
    }
    cout << endl;


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "| ";
            int cellValue = dataGrid[i][j].getValue();
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



// V�rifie si le jeu est termin� (plus de mouvements possibles)
void Data_Grid::checkGameOver() {

    if (emptyCells.empty()) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols - 1; j++) {
                if (dataGrid[i][j].getValue() == dataGrid[i][j + 1].getValue()) {
                    listGameover.push_back(0);
                }
                else {
                    listGameover.push_back(1);
                }
            }
        }

        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                if (dataGrid[i][j].getValue() == dataGrid[i + 1][j].getValue()) {
                    listGameover.push_back(0);
                }
                else {
                    listGameover.push_back(1);
                }
            }
        }

    }
}

// V�rifie si le jeu est termin� en se basant sur la v�rification pr�c�dente
bool Data_Grid::isGameOver() {
    checkGameOver();
    for (int i = 0; i < listGameover.size(); i++) {
        if (listGameover[i] == 0) {
            return false;
        }
    }
}

// R�initialise la liste de v�rification de fin du jeu
void Data_Grid::clearCheckGameOver() {
    listGameover.clear();
}

// Initialise la liste des cellules vides avec leur position dans la grille
void Data_Grid::initializeEmptyCells() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            emptyCells.push_back(make_pair(i, j));
        }
    }
}