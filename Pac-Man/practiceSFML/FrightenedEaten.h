#pragma once
#include "FrightenedBehaviour.h"
#include"Ghost.h"
class FrightenedEaten :public FrightenedBehaviour
{
private:
	Ghost* ptr;
public:
	FrightenedEaten(Ghost* ptr);
	void frightened() override;
	bool isValid(int x, int y);
	void gotHome();
};

