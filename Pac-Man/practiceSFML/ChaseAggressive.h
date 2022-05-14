#pragma once
#include"Ghost.h"
#include<queue>
class ChaseAggressive:public ChaseBehaviour
{
private:
	Ghost* ptr;
public:
	ChaseAggressive(Ghost *ptr);
	~ChaseAggressive();
	void chase() override;
	bool isValid(int x,int y);
};

