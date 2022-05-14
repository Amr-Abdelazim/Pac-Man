#include "ChaseAggressive.h"
#include<iostream>
#include"Global.h"
#include"Blinky.h"
ChaseAggressive::ChaseAggressive(Ghost* ptr)
{
	this->ptr = ptr;
	ptr->setChase();
}

ChaseAggressive::~ChaseAggressive()
{
	std::cout << "i'am in destructor !\n";
}

void ChaseAggressive::chase()
{
	int x = Global::player->x;
	int y = Global::player->y;
	if (x == ptr->x&&y == ptr->y)return;
	double mn = 1e9, dn = 0;
	double rightDis = Global::distance(x, y, ptr->x + 1, ptr->y);
	double leftDis = Global::distance(x, y, ptr->x - 1, ptr->y);
	double upDis = Global::distance(x, y, ptr->x, ptr->y - 1);
	double downDis = Global::distance(x, y, ptr->x, ptr->y + 1);
	bool rightValid = isValid(ptr->x + 1, ptr->y) && ptr->dir != 2;
	bool leftValid = isValid(ptr->x - 1, ptr->y) && ptr->dir != 0;
	bool upValid = isValid(ptr->x, ptr->y - 1) && ptr->dir != 1;
	bool downValid = isValid(ptr->x, ptr->y + 1) && ptr->dir != 3;
	if (rightValid)mn = rightDis, dn = 1;
	if (downValid&&downDis < mn)mn = downDis, dn = 2;
	if (leftValid&&leftDis < mn)mn = leftDis, dn = 3;
	if (upValid&&upDis < mn)mn = upDis, dn = 4;
	//std::cout << dn << "\n";
	if (dn == 1)ptr->MoveRight();
	else if (dn == 2)ptr->MoveDown();
	else if (dn == 3)ptr->MoveLeft();
	else if (dn == 4)ptr->MoveUp();
	else std::cout << "Ghost cant move !!!\n";
	Global::checkGate(ptr);
	/*if (Global::intersect(ptr->rec, Global::player->rec)) {
		Global::player->live--;
		ptr->x = 288;
		ptr->y = 320;
		ptr->sprite.setPosition(ptr->x, ptr->y);
		ptr->rec.setPosition(ptr->sprite.getPosition());
		Global::map->update();
	}*/

}

bool ChaseAggressive::isValid(int x, int y)
{
	sf::RectangleShape tmp;
	tmp.setPosition(x, y);
	tmp.setSize(sf::Vector2f(ptr->w, ptr->h));
	for (auto i : Global::objects) {
		if ((i->name == "wall"||(i->name=="door"&&((Ghost *)ptr)->getWaiting()))&&Global::intersect(tmp, i->rec))return false;
	}	
	return true;
}
