#pragma once
#include"ScatterBehaviour.h"
#include"Ghost.h"
class ScatterDownRight:public ScatterBehaviour
{
private:
	Ghost* ptr;
public:
	ScatterDownRight(Ghost* ptr);
	void scatter() override;
	bool isValid(int x, int y);
};

