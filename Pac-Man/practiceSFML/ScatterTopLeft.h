#pragma once
#include"ScatterBehaviour.h"
#include"Ghost.h"
class ScatterTopLeft:public ScatterBehaviour
{
private:
	Ghost* ptr;
public:
	ScatterTopLeft(Ghost* ptr);
	void scatter() override;
	bool isValid(int x, int y);
};

