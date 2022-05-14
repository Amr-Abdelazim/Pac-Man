#pragma once
#include"ScatterBehaviour.h"
#include"Ghost.h"
class ScatterTopRight:public ScatterBehaviour
{
private:
	Ghost* ptr;
public:
	ScatterTopRight(Ghost* ptr);
	void scatter() override;
	bool isValid(int x, int y);
};

