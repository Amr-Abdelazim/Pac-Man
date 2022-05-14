#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{
	virtual void update();
	virtual void render(sf::RenderWindow &window);
};

