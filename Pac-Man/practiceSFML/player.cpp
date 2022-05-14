#include "player.h"
#include"keyboard.h"
#include"Global.h"
#include"Blinky.h"
#include<iostream>
#include<iomanip>

Player::Player(int x, int y) :Object(x, y, 14, 4, 10, 0, "image/SpriteSheet.png","player")
{
	this->speed = 2;
	this->cnt = 0;
	this->delay = 5;
	//this->rec.setSize(sf::Vector2f(25,25));
	this->dir = -1;
	this->live = 3;
}
void Player::update() {
	//std::cout << x << " " << y << "\n";
	animate();
	int Tx = x, Ty = y;
	if (keyboard::left) {
		Tx -= speed;
		if (isValid(Tx, Ty)) dir = 2;		
	}
	if (keyboard::right) {
		Tx += speed;
		if (isValid(Tx, Ty)) dir = 0;	
	}		
	if (keyboard::up) {
		Ty -= speed;
		if (isValid(Tx, Ty)) dir = 3;		
	}
	if (keyboard::down) {
		Ty += speed;
		if (isValid(Tx, Ty)) dir = 1;	
	}
	
	if (dir == 0) {
		if (isValid(x + speed, y))x += speed;
	}
	else if (dir == 1) {
		if (isValid(x, y + speed))y += speed;
	}
	else if (dir == 2) {
		if (isValid(x - speed, y))x -= speed;
	}
	else if (dir == 3) {
		if (isValid(x, y - speed))y -= speed;
	}
	Global::checkGate(this);
	if (isDot(x, y))Global::score += 10;
	rec.setPosition(x , y );
	sprite.setPosition(x, y);
	ghostChacker();
}
void Player::render(sf::RenderWindow &window) {	
	//window.draw(rec);
	window.draw(sprite);
}

void Player::animate()
{
	//std::cout << std::fixed<<std::setprecision(6)<<w<<" "<<h<<"\n";
	sprite.setTextureRect(sf::IntRect((double)(cur*w), (double)(fmax(dir,0)*h), w, h));
	cnt++;
	if(cnt%delay==0)
	cur = 10+(cur + 1) % 2,cnt=0;
}
bool Player::isValid(int x, int y)
{
	sf::RectangleShape tmp = rec;
	tmp.setPosition(x, y);
	for (auto &i : Global::objects) {
		if (i->name == "wall"&&Global::intersect(tmp, i->rec))return false;
	}
	return true;
}
bool Player::isDot(int x, int y)
{
	sf::RectangleShape tmp = rec;
	tmp.setPosition(x, y);
	tmp.setSize(sf::Vector2f(10, 10));
	int dx = 0;
	for (auto &i : Global::objects) {
		if (i->name == "dot"&&Global::intersect(tmp, i->rec)) {
			delete Global::objects[dx];
			Global::objects.erase(Global::objects.begin()+dx);
			return true;
		}
		else if (i->name == "bigDot"&&Global::intersect(tmp, i->rec)) {
			// set Frightened Mode for all ghosts
			for (auto &j : Global::objects)
				if (j->name == "scatter" || j->name == "chaser" || j->name == "frightened")
					((Ghost*)j)->setFrightenedMode();

			delete Global::objects[dx];
			Global::objects.erase(Global::objects.begin() + dx);
			return true;
		}
		dx++;
	}
	return false;
}

void Player::ghostChacker()
{
	sf::RectangleShape tmp = rec;
	tmp.setPosition(x, y);
	tmp.setSize(sf::Vector2f(10, 10));
	for (auto i : Global::objects)
		if ((i->name == "scatter" || i->name == "chaser") && Global::intersect(tmp, i->rec))
			PacmanDead();
		else if (i->name == "frightened" && Global::intersect(tmp, i->rec))
			((Ghost*)i)->setEatenMode();
}

void Player::PacmanDead()
{
}

