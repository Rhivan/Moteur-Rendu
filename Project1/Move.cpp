#include "Move.h"

void Move::moveLeft(Data_Grid& grid) {
	for (int row = 0; row < grid.rows; row++) {

		for (int col = 1; col < grid.cols; col++) {
			if (!grid.dataGrid[row][col].isEmptyCell()) {
				int currentCol = col;
				
				
				while (currentCol > 0) {
					// si la cellule à gauche de la cellule actuelle est vide on deplace la cellule actuelle vers la gauche et on rend vide l'ancienne 
					if (grid.dataGrid[row][currentCol - 1].isEmptyCell()) {
						grid.dataGrid[row][currentCol - 1].setValue(grid.dataGrid[row][currentCol].getValue());
						grid.dataGrid[row][currentCol].setEmpty();
						currentCol--;
						moved = true;
					}
					//si la cellule à gauche de la cellule actuelle est egale à la cellule de gauche et quelle n'a pas deja fusionné on fusionne les deux cellules et on rend vide l'ancienne
					else if (grid.dataGrid[row][currentCol - 1].getValue() == grid.dataGrid[row][currentCol].getValue() && grid.dataGrid[row][currentCol - 1].isMergedCell() == false) {
						int mergedValue = grid.dataGrid[row][currentCol].getValue() * 2;
						grid.dataGrid[row][currentCol - 1].setValue(mergedValue);
						grid.dataGrid[row][currentCol].setEmpty();
						grid.dataGrid[row][currentCol - 1].setMergedCell();
						moved = true;
						break; //Pas plus de une fusion par tour donc sortie de la boucle
					}
					else {
						break; //Aucune fusion possible sortie de la boucle
					}
				}

			}
		}
	}
}

void Move::moveRight(Data_Grid& grid) {
	for (int row = 0; row < grid.rows; row++) {

		for (int col = grid.cols - 2; col >= 0; col--) {
			if (!grid.dataGrid[row][col].isEmptyCell()) {
				int currentCol = col;

				while (currentCol < grid.cols - 1) {
					// si la cellule à droite de la cellule actuelle est vide on deplace la cellule actuelle vers la droite et on rend vide l'ancienne 
					if (grid.dataGrid[row][currentCol + 1].isEmptyCell()) {
						grid.dataGrid[row][currentCol + 1].setValue(grid.dataGrid[row][currentCol].getValue());
						grid.dataGrid[row][currentCol].setEmpty();
						currentCol++;
						moved = true;
					}
					//si la cellule à droite de la cellule actuelle est egale à la cellule actuelle et que la cellule à droite n'a pas deja fusionné
					else if (grid.dataGrid[row][currentCol + 1].getValue() == grid.dataGrid[row][currentCol].getValue() && grid.dataGrid[row][currentCol + 1].isMergedCell() == false) {
						int mergedValue = grid.dataGrid[row][currentCol].getValue() * 2;
						grid.dataGrid[row][currentCol + 1].setValue(mergedValue);
						grid.dataGrid[row][currentCol].setEmpty();
						grid.dataGrid[row][currentCol + 1].setMergedCell();
						moved = true;
						break; //Pas plus de une fusion par tour donc sortie de la boucle
					}
					else {
						break; //Aucune fusion possible sortie de la boucle
					}
				}
			}
		}
	}
}

void Move::moveUp(Data_Grid& grid) {
	for (int col = 0; col < grid.cols; col++) {

		for (int row = 1; row < grid.rows; row++) {
			if (!grid.dataGrid[row][col].isEmptyCell()) {
				int currentRow = row;
				// si la cellule au dessus de la cellule actuelle est vide on deplace la cellule actuelle vers le haut et on rend vide l'ancienne 

				while (currentRow > 0) {
					if (grid.dataGrid[currentRow - 1][col].isEmptyCell()) {
						grid.dataGrid[currentRow - 1][col].setValue(grid.dataGrid[currentRow][col].getValue());
						grid.dataGrid[currentRow][col].setEmpty();
						currentRow--;
						moved = true;
					}
					else if (grid.dataGrid[currentRow - 1][col].getValue() == grid.dataGrid[currentRow][col].getValue() && grid.dataGrid[currentRow - 1][col].isMergedCell() == false) {
						int mergedValue = grid.dataGrid[currentRow][col].getValue() * 2;
						grid.dataGrid[currentRow - 1][col].setValue(mergedValue);
						grid.dataGrid[currentRow][col].setEmpty();
						grid.dataGrid[currentRow - 1][col].setMergedCell();
						moved = true;
						break; //Pas plus de une fusion par tour donc sortie de la boucle
					}
					else {
						break; //Aucune fusion possible sortie de la boucle
					}
				}

			}
		}
	}
}

void Move::moveDown(Data_Grid& grid) {
	for (int col = 0; col < grid.cols; col++) {

		for (int row = grid.rows - 1; row >= 0; row--) {
			if (!grid.dataGrid[row][col].isEmptyCell()) {
				int currentRow = row;
				// si la cellule en dessous de la cellule actuelle est vide on deplace la cellule actuelle vers le bas et on rend vide l'ancienne 

				while (currentRow < grid.rows - 1) {
					if (grid.dataGrid[currentRow + 1][col].isEmptyCell()) {
						grid.dataGrid[currentRow + 1][col].setValue(grid.dataGrid[currentRow][col].getValue());
						grid.dataGrid[currentRow][col].setEmpty();
						currentRow++;
						moved = true;
					}
					else if (grid.dataGrid[currentRow + 1][col].getValue() == grid.dataGrid[currentRow][col].getValue() && grid.dataGrid[currentRow + 1][col].isMergedCell() == false) {
						int mergedValue = grid.dataGrid[currentRow][col].getValue() * 2;
						grid.dataGrid[currentRow + 1][col].setValue(mergedValue);
						grid.dataGrid[currentRow][col].setEmpty();
						grid.dataGrid[currentRow + 1][col].setMergedCell();
						moved = true;
						break; //Pas plus de une fusion par tour donc sortie de la boucle
					}
					else {
						break; //Aucune fusion possible sortie de la boucle
					}
				}

			}
		}
	}
}


