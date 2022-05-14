#pragma once
#include"GameObject.h"
class Object:public GameObject 
{
public:
	int cur, dir;
	sf::Texture texture;
	int x, y;
	double w, h, speed;
	sf::Sprite sprite;
	std::string name;
	sf::RectangleShape rec;
	Object();
	Object(int x, int y,double w,double h,int cur,int dir,std::string fileName,std::string name);
	virtual void animate();
	void update() override;
	void render(sf::RenderWindow &window)override;
};

