#include "FrightenedWandering.h"
#include"Global.h"
#include<iostream>
#include<time.h>
FrightenedWandering::FrightenedWandering(Ghost * ptr)
{
	this->ptr = ptr;
	ptr->setFrightened();
	if (ptr->dir == 0)ptr->dir = 2;
	else if (ptr->dir == 1)ptr->dir = 3;
	else if (ptr->dir == 2)ptr->dir = 0;
	else if (ptr->dir == 3)ptr->dir = 1;
}

void FrightenedWandering::frightened()
{
	int x = Global::player->x;
	int y = Global::player->y;
	if (x == ptr->x&&y == ptr->y)return;
	double dn = 0;
	bool rightValid = isValid(ptr->x + 1, ptr->y) && ptr->dir != 2;
	bool leftValid = isValid(ptr->x - 1, ptr->y) && ptr->dir != 0;
	bool upValid = isValid(ptr->x, ptr->y - 1) && ptr->dir != 1;
	bool downValid = isValid(ptr->x, ptr->y + 1) && ptr->dir != 3;
	std::vector<int>vec;
	if (rightValid)vec.push_back(1);
	if (downValid)vec.push_back(2);
	if (leftValid)vec.push_back(3);
	if (upValid)vec.push_back(4);

	dn = vec[rand() % vec.size()];
	if (dn == 1)ptr->MoveRight();
	else if (dn == 2)ptr->MoveDown();
	else if (dn == 3)ptr->MoveLeft();
	else if (dn == 4)ptr->MoveUp();
	else std::cout << "Ghost cant move !!!\n";
	Global::checkGate(ptr);
}
bool FrightenedWandering::isValid(int x, int y)
{
	sf::RectangleShape tmp;
	tmp.setPosition(x, y);
	tmp.setSize(sf::Vector2f(ptr->w, ptr->h));
	for (auto i : Global::objects) {
		if ((i->name == "wall" || (i->name == "door" && ((Ghost *)ptr)->getWaiting())) && Global::intersect(tmp, i->rec))return false;
	}
	return true;
}
