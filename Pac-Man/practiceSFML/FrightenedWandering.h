#pragma once
#include"FrightenedBehaviour.h"
#include"Ghost.h"
class FrightenedWandering:public FrightenedBehaviour {
private:
	Ghost* ptr;
public:
	FrightenedWandering(Ghost * ptr);
	bool isValid(int x, int y);
	void frightened() override;
};