//#include "Move.h"
//
//void Move::moveLeft(Grid& grid) {
//	for (int row = 0; row < grid.rows; row++) {
//
//		for (int col = 1; col < grid.cols; col++) {
//			if (!grid.grid[row][col].isEmptyCell()) {
//				int currentCol = col;
//				
//				
//				while (currentCol > 0) {
//					// si la cellule à gauche de la cellule actuelle est vide on deplace la cellule actuelle vers la gauche et on rend vide l'ancienne 
//					if (grid.grid[row][currentCol - 1].isEmptyCell()) {
//						grid.grid[row][currentCol - 1].setValue(grid.grid[row][currentCol].getValue());
//						grid.grid[row][currentCol].setEmpty();
//						currentCol--;
//						moved = true;
//					}
//					//si la cellule à gauche de la cellule actuelle est egale à la cellule de gauche et quelle n'a pas deja fusionné on fusionne les deux cellules et on rend vide l'ancienne
//					else if (grid.grid[row][currentCol - 1].getValue() == grid.grid[row][currentCol].getValue() && grid.grid[row][currentCol - 1].isMergedCell() == false) {
//						int mergedValue = grid.grid[row][currentCol].getValue() * 2;
//						grid.grid[row][currentCol - 1].setValue(mergedValue);
//						grid.grid[row][currentCol].setEmpty();
//						grid.grid[row][currentCol - 1].setMergedCell();
//						moved = true;
//						break; //Pas plus de une fusion par tour donc sortie de la boucle
//					}
//					else {
//						break; //Aucune fusion possible sortie de la boucle
//					}
//				}
//
//			}
//		}
//	}
//}
//
//void Move::moveRight(Grid& grid) {
//	for (int row = 0; row < grid.rows; row++) {
//
//		for (int col = grid.cols - 2; col >= 0; col--) {
//			if (!grid.grid[row][col].isEmptyCell()) {
//				int currentCol = col;
//
//				while (currentCol < grid.cols - 1) {
//					// si la cellule à droite de la cellule actuelle est vide on deplace la cellule actuelle vers la droite et on rend vide l'ancienne 
//					if (grid.grid[row][currentCol + 1].isEmptyCell()) {
//						grid.grid[row][currentCol + 1].setValue(grid.grid[row][currentCol].getValue());
//						grid.grid[row][currentCol].setEmpty();
//						currentCol++;
//						moved = true;
//					}
//					//si la cellule à droite de la cellule actuelle est egale à la cellule actuelle et que la cellule à droite n'a pas deja fusionné
//					else if (grid.grid[row][currentCol + 1].getValue() == grid.grid[row][currentCol].getValue() && grid.grid[row][currentCol + 1].isMergedCell() == false) {
//						int mergedValue = grid.grid[row][currentCol].getValue() * 2;
//						grid.grid[row][currentCol + 1].setValue(mergedValue);
//						grid.grid[row][currentCol].setEmpty();
//						grid.grid[row][currentCol + 1].setMergedCell();
//						moved = true;
//						break; //Pas plus de une fusion par tour donc sortie de la boucle
//					}
//					else {
//						break; //Aucune fusion possible sortie de la boucle
//					}
//				}
//			}
//		}
//	}
//}
//
//void Move::moveUp(Grid& grid) {
//	for (int col = 0; col < grid.cols; col++) {
//
//		for (int row = 1; row < grid.rows; row++) {
//			if (!grid.grid[row][col].isEmptyCell()) {
//				int currentRow = row;
//				// si la cellule au dessus de la cellule actuelle est vide on deplace la cellule actuelle vers le haut et on rend vide l'ancienne 
//
//				while (currentRow > 0) {
//					if (grid.grid[currentRow - 1][col].isEmptyCell()) {
//						grid.grid[currentRow - 1][col].setValue(grid.grid[currentRow][col].getValue());
//						grid.grid[currentRow][col].setEmpty();
//						currentRow--;
//						moved = true;
//					}
//					else if (grid.grid[currentRow - 1][col].getValue() == grid.grid[currentRow][col].getValue() && grid.grid[currentRow - 1][col].isMergedCell() == false) {
//						int mergedValue = grid.grid[currentRow][col].getValue() * 2;
//						grid.grid[currentRow - 1][col].setValue(mergedValue);
//						grid.grid[currentRow][col].setEmpty();
//						grid.grid[currentRow - 1][col].setMergedCell();
//						moved = true;
//						break; //Pas plus de une fusion par tour donc sortie de la boucle
//					}
//					else {
//						break; //Aucune fusion possible sortie de la boucle
//					}
//				}
//
//			}
//		}
//	}
//}
//
//void Move::moveDown(Grid& grid) {
//	for (int col = 0; col < grid.cols; col++) {
//
//		for (int row = grid.rows - 1; row >= 0; row--) {
//			if (!grid.grid[row][col].isEmptyCell()) {
//				int currentRow = row;
//				// si la cellule en dessous de la cellule actuelle est vide on deplace la cellule actuelle vers le bas et on rend vide l'ancienne 
//
//				while (currentRow < grid.rows - 1) {
//					if (grid.grid[currentRow + 1][col].isEmptyCell()) {
//						grid.grid[currentRow + 1][col].setValue(grid.grid[currentRow][col].getValue());
//						grid.grid[currentRow][col].setEmpty();
//						currentRow++;
//						moved = true;
//					}
//					else if (grid.grid[currentRow + 1][col].getValue() == grid.grid[currentRow][col].getValue() && grid.grid[currentRow + 1][col].isMergedCell() == false) {
//						int mergedValue = grid.grid[currentRow][col].getValue() * 2;
//						grid.grid[currentRow + 1][col].setValue(mergedValue);
//						grid.grid[currentRow][col].setEmpty();
//						grid.grid[currentRow + 1][col].setMergedCell();
//						moved = true;
//						break; //Pas plus de une fusion par tour donc sortie de la boucle
//					}
//					else {
//						break; //Aucune fusion possible sortie de la boucle
//					}
//				}
//
//			}
//		}
//	}
//}
//
//
