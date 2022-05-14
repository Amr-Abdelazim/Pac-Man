#include "Map.h"
#include"player.h"
#include"Global.h"
#include<iostream>
Map::Map(){}
Map::Map(std::string fileName)
{
	a = b = 0;
	std::freopen(fileName.c_str(), "r", stdin);
	std::string line;
	while (std::getline(std::cin,line)) {
		for (int i = 0; i < line.size(); i++) {
			std::string name="wall";
			int c1 = -1, c2 = -1;
			if (line[i] == '#')c1 = 7, c2 = 13;
			else if (line[i] == '|')c1 = 6, c2 = 13;
			else if (line[i] == '0')c1 = 6, c2 = 10;
			else if (line[i] == '1')c1 = 7, c2 = 10;
			else if (line[i] == '2')c1 = 8, c2 = 10;
			else if (line[i] == '3')c1 = 6, c2 = 11;
			else if (line[i] == '4')c1 = 7, c2 = 11;
			else if (line[i] == '5')c1 = 8, c2 = 11;
			else if (line[i] == '6')c1 = 6, c2 = 12;
			else if (line[i] == '7')c1 = 7, c2 = 12;
			else if (line[i] == '8')c1 = 8, c2 = 12;
			else if (line[i] == '>')c1 = 10, c2 = 13;
			else if (line[i] == '<')c1 = 9, c2 = 13;
			else if (line[i] == 'v')c1 = 9, c2 = 12;
			else if (line[i] == '^')c1 = 10, c2 = 12;
			else if (line[i] == '*')c1 = 12, c2 = 8;
			else if (line[i] == '.')c1 = 12, c2 = 0,name="dot";
			else if (line[i] == 'x')c1 = 10, c2 = 4,name="door";
			else if (line[i] == 'y')c1 = 10, c2 = 3,name="door";
			else if (line[i] == 'O')c1 = 13, c2 = 0, name = "bigDot";
			if (c1!=-1) {
				wall.push_back(new Object(a, b, 17, 14, c1, c2, "image/SpriteSheet2.png", name));
				if(c2!=0)
				wall.back()->sprite.setColor(sf::Color::Blue);
				Global::objects.push_back(wall.back());				
			}
			a += 32;		
		}
		a = 0;
		b += 32;;
	}
	if (Global::player != NULL) {
		int Ta = a, Tb = b;
		for (int i = 0; i < ((Player *)Global::player)->live; i++, Ta += 32)
			Global::objects.push_back(new Object(Ta, Tb, 17, 14, 7, 8, "image/SpriteSheet2.png", "live"));
	}
}

void Map::update()
{
	for (int i = 0; i < Global::objects.size(); i++) {
		if (Global::objects[i]->name == "live") {
			Global::objects.erase(Global::objects.begin() + i);
			i--;
		}
	}
	int Ta = a, Tb = b;
	std::cout << Global::player->live << "\n";
	for (int i = 0; i < Global::player->live; i++, Ta += 32)
		Global::objects.push_back(new Object(Ta, Tb, 17, 14, 7, 8, "image/SpriteSheet2.png", "live"));
}

void Map::render(sf::RenderWindow & window)
{
	for (auto i : wall) {
		i->render(window);
	}
}
