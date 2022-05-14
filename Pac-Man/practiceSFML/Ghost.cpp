#include "Ghost.h"
#include"keyboard.h"
#include<iostream>

Ghost::Ghost(int x, int y):Object(x,y,14,4,0,0,"image/SpriteSheet.png","ghost"),homeX(x),homeY(y)
{
	chaseBehaviour = NULL;
	frightenedBehaviour = NULL;
	scatterBehaviour = NULL;
	delay = 10;
	Tcur = cnt = 0;
	lastTime = clock();
	eaten = false;
	waiting = true;
	chaseMode = frightenedMode = scatterMode = false;
	speed = 1;	
}


void Ghost::animate()
{
	//std::cout << cur << " " << getDir() << "\n";
	sprite.setTextureRect(sf::IntRect((double)(cur*w), (double)(getDir()*h), w, h));
	cnt++;
	if (cnt%delay == 0)
		cur =  Tcur+(cur + 1) % 2, cnt = 0;	
}

void Ghost::update()
{
	animate();
	Move();
}
void Ghost::render(sf::RenderWindow & window)
{
	//window.draw(rec);
	window.draw(sprite);	
}

void Ghost::MoveLeft()
{
	dir = 2;
	x -= 1;
	rec.setPosition(x+3, y+3);
	sprite.setPosition(x, y);
}
void Ghost::MoveRight()
{
	dir = 0;
	x += 1;
	rec.setPosition(x + 3, y + 3);
	sprite.setPosition(x, y);
}
void Ghost::MoveUp()
{
	dir = 3;
	y -= 1;
	rec.setPosition(x + 3, y + 3);
	sprite.setPosition(x, y);
}
void Ghost::MoveDown()
{
	dir = 1;
	y += 1;
	rec.setPosition(x + 3, y + 3);
	sprite.setPosition(x, y);
}

void Ghost::setFrightened()
{
	this->name = "frightened";
	this->cur = 12;
	Tcur = 12;
	frightenedMode = true;
	scatterMode = chaseMode = false;
}

bool Ghost::getWaiting()
{
	return waiting;
}

std::pair<int, int> Ghost::getHomePosition()
{
	return std::pair<int, int>(homeX,homeY);
}

int Ghost::getDir()
{
	if (frightenedMode)return 0;
	if (eaten)return 2;
	return dir;
}
