#pragma once
#include <vector>
#include "Cell.h"

using namespace std;

class Data_Grid {
public:

    int rows;
    int cols;

    Data_Grid(int numRows, int numCols);
    Data_Grid(vector<vector<int>>& setup);

    void generateRandomCell();
    void updateEmptyCells();
    void updateMergedCells();
    void display();
    void checkGameOver();
    bool isGameOver();
    void clearCheckGameOver();

    vector<pair<int, int>> emptyCells;

    vector<int> listGameover;

    vector<vector<Cell>> dataGrid;

    void initializeEmptyCells();
private:

};

