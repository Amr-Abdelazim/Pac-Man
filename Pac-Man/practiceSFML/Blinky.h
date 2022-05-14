#pragma once
#include"Ghost.h"
#include"keyboard.h"
class Blinky:public Ghost
{	
private:
	time_t timeMode;
	double getTime(time_t lastTime);
	void freePointer();
	
public :
	
	Blinky(int x,int y);
	~Blinky();
	void update() override;
	void Move() override;
	void setChase() override;
	void setScatter() override;
	void setFrightenedMode() override;
	void setScatterMode() override;
	void setChaserMode() override;
	void setEatenMode() override;
};

