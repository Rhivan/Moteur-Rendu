#include <vector>
#include "Cell.h"

using namespace std;

class Grid {
public:

    int rows;
    int cols;

    Grid(int numRows, int numCols);
    Grid(vector<vector<int>>& setup);

    void generateRandomCell();
    void updateEmptyCells();
    void updateMergedCells();
    void display();
    void checkGameOver();
    bool isGameOver();
    void clearCheckGameOver();

    vector<pair<int, int>> emptyCells;

    vector<int> listGameover;

    vector<vector<Cell>> grid;

    void initializeEmptyCells();
private:
    
};


