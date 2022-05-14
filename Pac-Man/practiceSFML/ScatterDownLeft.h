#pragma once
#include"ScatterBehaviour.h"
#include"Ghost.h"
class ScatterDownLeft:public ScatterBehaviour
{
private:
	Ghost* ptr;
public:
	ScatterDownLeft(Ghost* ptr);
	void scatter() override;
	bool isValid(int x, int y);
};

