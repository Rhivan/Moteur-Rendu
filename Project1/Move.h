#include "Grid.h"

class Move
{
public:

	void moveLeft(Grid& grid);
	void moveRight(Grid& grid);
	void moveUp(Grid& grid);
	void moveDown(Grid& grid);
	bool moved = false;

};