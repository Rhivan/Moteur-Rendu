#include "Data_Grid.h"

class Move
{
public:

	void moveLeft(Data_Grid& grid);
	void moveRight(Data_Grid& grid);
	void moveUp(Data_Grid& grid);
	void moveDown(Data_Grid& grid);
	bool moved = false;

};