#pragma once
#include<vector>
#include"Object.h"
#include"player.h"
#include"Map.h"

class Global
{
public:
	static std::vector<Object*>objects;
	static Player* player;
	static Map* map;
	static int score;
	static bool intersect(sf::RectangleShape rec1, sf::RectangleShape rec2);
	static double distance(int x1,int y1,int x2,int y2);
	static void checkGate(Object* ptr);
};