#pragma once
#include <SFML/Graphics.hpp>
#include"GameObject.h"
#include"Object.h"
#include"ChaseBehaviour.h"
#include"FrightenedBehaviour.h"
#include"ScatterBehaviour.h"
class Ghost:public Object
{
private:
	int getDir();
	const int homeX, homeY;
protected:
	ChaseBehaviour* chaseBehaviour;
	FrightenedBehaviour* frightenedBehaviour;
	ScatterBehaviour* scatterBehaviour;	
	int delay, cnt, Tcur;
	clock_t lastTime;
	bool eaten, waiting;
	bool chaseMode, frightenedMode, scatterMode;
	void virtual Move() = 0;
	
public:
	Ghost(int x,int y);
	void animate() override;
	void update() override;
	void render(sf::RenderWindow &window) override;
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void virtual setChase() = 0;
	void virtual setScatter() = 0;
	void virtual setFrightened();
	void virtual setFrightenedMode() = 0;
	void virtual setScatterMode() = 0;
	void virtual setChaserMode() = 0;
	void virtual setEatenMode() = 0;
	bool getWaiting();
	std::pair<int, int> getHomePosition();
};

