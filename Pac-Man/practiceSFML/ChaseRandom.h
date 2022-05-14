#pragma once
#include"ChaseBehaviour.h"
#include"Ghost.h"
class ChaseRandom:public ChaseBehaviour
{
private:
	Ghost* ptr;
public:
	ChaseRandom(Ghost* ptr);
	~ChaseRandom();
	void chase() override;
};

