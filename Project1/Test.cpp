//#include "Test.h"
//#include <iostream>;
//
//
//void Test::gridLeft() {
//	vector<vector<int>> setup = {
//		{ 0, 2, 2, 0 },
//		{ 0, 2, 0, 0 },
//		{ 0, 2, 0, 0 },
//		{ 0, 2, 0, 0 }
//	};
//
//	Grid oGrid(setup);
//	oGrid.display();
//
//	Move move;
//
//	// Effectuer le mouvement vers la gauche
//	move.moveLeft(oGrid);
//	cout << "Apres le mouvement vers la gauche :" << endl;
//	oGrid.display();
//
//	// Vérifier si le mouvement a fonctionné correctement en comparant avec un état attendu.
//	vector<vector<int>> expected = {
//		{ 4, 0, 0, 0 },
//		{ 2, 0, 0, 0 },
//		{ 2, 0, 0, 0 },
//		{ 2, 0, 0, 0 }
//	};
//
//	// Vérifier si la grille correspond à l'état attendu après le mouvement.
//	bool success = true;
//	for (int i = 0; i < oGrid.rows; ++i) {
//		for (int j = 0; j < oGrid.cols; ++j) {
//			if (oGrid.grid[i][j].getValue() != expected[i][j]) {
//				success = false;
//				break;
//			}
//		}
//		if (!success) {
//			break;
//		}
//	}
//
//	if (success) {
//		cout << "Test reussi : le mouvement vers la gauche est correct." << endl;
//	}
//	else {
//		cout << "Test echoue : le mouvement vers la gauche est incorrect." << endl;
//	}
//};
//
//void Test::gridRight() {
//	vector<vector<int>> setup = {
//		{ 0, 2, 2, 0 },
//		{ 0, 2, 0, 0 },
//		{ 0, 2, 0, 0 },
//		{ 0, 2, 0, 0 }
//	};
//
//	Grid oGrid(setup);
//	oGrid.display();
//
//	Move move;
//
//	// Effectuer le mouvement vers la droite
//	move.moveRight(oGrid);
//	cout << "Apres le mouvement vers la droite :" << endl;
//	oGrid.display();
//
//	// Vérifier si le mouvement a fonctionné correctement en comparant avec un état attendu.
//	vector<vector<int>> expected = {
//		{ 0, 0, 0, 4 },
//		{ 0, 0, 0, 2 },
//		{ 0, 0, 0, 2 },
//		{ 0, 0, 0, 2 }
//	};
//
//	// Vérifier si la grille correspond à l'état attendu après le mouvement.
//	bool success = true;
//	for (int i = 0; i < oGrid.rows; ++i) {
//		for (int j = 0; j < oGrid.cols; ++j) {
//			if (oGrid.grid[i][j].getValue() != expected[i][j]) {
//				success = false;
//				break;
//			}
//		}
//		if (!success) {
//			break;
//		}
//	}
//
//	if (success) {
//		cout << "Test reussi : le mouvement vers la droite est correct." << endl;
//	}
//	else {
//		cout << "Test echoue : le mouvement vers la droite est incorrect." << endl;
//	}
//};
//
//void Test::gridUp() {
//	vector<vector<int>> setup = {
//		{ 0, 0, 0, 0 },
//		{ 0, 2, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 2, 2, 2, 2 }
//	};
//
//	Grid oGrid(setup);
//	oGrid.display();
//
//	Move move;
//
//	// Effectuer le mouvement vers le haut
//	move.moveUp(oGrid);
//	cout << "Apres le mouvement vers le haut :" << endl;
//	oGrid.display();
//
//	// Vérifier si le mouvement a fonctionné correctement en comparant avec un état attendu.
//	vector<vector<int>> expected = {
//		{ 2, 4, 2, 2 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 }
//		
//	};
//
//	// Vérifier si la grille correspond à l'état attendu après le mouvement.
//	bool success = true;
//	for (int i = 0; i < oGrid.rows; ++i) {
//		for (int j = 0; j < oGrid.cols; ++j) {
//			if (oGrid.grid[i][j].getValue() != expected[i][j]) {
//				success = false;
//				break;
//			}
//		}
//		if (!success) {
//			break;
//		}
//	}
//
//	if (success) {
//		cout << "Test reussi : le mouvement vers le haut est correct." << endl;
//	}
//	else {
//		cout << "Test echoue : le mouvement vers le haut est incorrect." << endl;
//	}
//};
//
//void Test::gridDown() {
//	vector<vector<int>> setup = {
//		{ 2, 2, 2, 2 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 2 },
//		{ 0, 0, 0, 0 }
//	};
//
//	Grid oGrid(setup);
//	oGrid.display();
//
//	Move move;
//
//	// Effectuer le mouvement vers le bas
//	move.moveDown(oGrid);
//	cout << "Apres le mouvement vers le bas :" << endl;
//	oGrid.display();
//
//	// Vérifier si le mouvement a fonctionné correctement en comparant avec un état attendu.
//	vector<vector<int>> expected = {
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 0, 0, 0, 0 },
//		{ 2, 2, 2, 4 }
//	};
//
//	// Vérifier si la grille correspond à l'état attendu après le mouvement.
//	bool success = true;
//	for (int i = 0; i < oGrid.rows; ++i) {
//		for (int j = 0; j < oGrid.cols; ++j) {
//			if (oGrid.grid[i][j].getValue() != expected[i][j]) {
//				success = false;
//				break;
//			}
//		}
//		if (!success) {
//			break;
//		}
//	}
//
//	if (success) {
//		cout << "Test reussi : le mouvement vers le bas est correct." << endl;
//	}
//	else {
//		cout << "Test echoue : le mouvement vers le bas est incorrect." << endl;
//	}
//};