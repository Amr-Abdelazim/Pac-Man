#include "Object.h"

Object::Object()
{
}

Object::Object(int x, int y,double w,double h,int cur,int dir,std::string fileName,std::string name)
{
	this->name = name;
	texture.loadFromFile(fileName);
	sprite.setTexture(texture);
	this->w = texture.getSize().x / w;
	this->h = texture.getSize().y / h;
	sprite.setTextureRect(sf::IntRect(cur*this->w+1, dir*this->h+1, this->w-1, this->h-1));
	sprite.setScale(32 / this->w, 32 / this->h);
	sprite.setPosition((float)x, (float)y);
	this->x = x;
	this->y = y;
	this->dir = dir;
	this->cur = cur;
	this->speed = 1;
	rec.setPosition(x, y);
	if(name=="dot")
	rec.setSize(sf::Vector2f(10, 10));
	else
	rec.setSize(sf::Vector2f(32, 32));
	rec.setFillColor(sf::Color::Red);
	//rec.setOutlineThickness(-1);
}

void Object::animate()
{
}

void Object::update()
{
}

void Object::render(sf::RenderWindow & window)
{
	window.draw(sprite);
	//window.draw(rec);
}

