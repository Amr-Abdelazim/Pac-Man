#include "keyboard.h"

bool keyboard::up = false;
bool keyboard::down = false;
bool keyboard::left = false;
bool keyboard::right = false;

void keyboard::Up()
{
	up = true;
	left = right = down = false;
}

void keyboard::Down()
{
	down = true;
	left = right = up = false;
}

void keyboard::Left()
{
	left = true;
	right = up = down = false;
}

void keyboard::Right()
{
	right = true;
	left = up = down = false;
}

void keyboard::clear()
{
	right = left = up = down = false;
}
