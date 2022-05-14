#pragma once
#include"Object.h"


class Map
{
private:
	std::vector<Object*>wall;
	int a, b;
public:
	Map();
	Map(std::string fileName);
	void update() ;
	void render(sf::RenderWindow &window) ;
};

