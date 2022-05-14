#pragma once
#include <SFML/Graphics.hpp>
#include"GameObject.h"
#include"Object.h"
class Player:public Object
{
private:
	int cnt, delay;
	void PacmanDead();
public:
	int live;
	Player(int x, int y);
	void update() override;
	void render(sf::RenderWindow &window) override;
	void animate() override;
	bool isValid(int x, int y);
	bool isDot(int x, int y);
	void ghostChacker();
};

