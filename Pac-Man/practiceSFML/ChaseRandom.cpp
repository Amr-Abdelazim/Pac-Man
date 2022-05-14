#include "ChaseRandom.h"

ChaseRandom::ChaseRandom(Ghost* ptr)
{
	this->ptr = ptr;
}

ChaseRandom::~ChaseRandom()
{
}

void ChaseRandom::chase()
{
	ptr->MoveLeft();
}
