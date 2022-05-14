#include "Global.h"
#include<cmath>
std::vector<Object*>Global::objects;
Player* Global::player=NULL;
Map* Global::map = NULL;
int Global::score = 0;
bool Global::intersect(sf::RectangleShape rec1, sf::RectangleShape rec2)
{
	double w1 = rec1.getSize().x,w2= rec2.getSize().x;
	double h1 = rec1.getSize().y, h2 = rec2.getSize().y;
	double x1 = rec1.getPosition().x, y1 = rec1.getPosition().y;
	double x2 = rec2.getPosition().x, y2 = rec2.getPosition().y;
	double Wmx = fmax(x1 + w1, x2 + w2) - fmin(x1, x2);
	double Hmx = fmax(y1 + h1, y2 + h2) - fmin(y1, y2);
	return Wmx<w1+w2&&Hmx<h1+h2;
}

double Global::distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

void Global::checkGate(Object* ptr)
{
	int &x = ptr->x, &y = ptr->y;
	if (x < 0) x = 510, y = 384;
	else if (x > 515)x = 0, y = 160;
	else if (y < 0)y = 544, x = 160;
	else if (y > 544)y = 0, x = 352;
	ptr->rec.setPosition(x, y);
	ptr->sprite.setPosition(x, y);
}
