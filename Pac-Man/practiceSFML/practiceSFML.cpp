#include <iostream>
#include <SFML/Graphics.hpp>
#include"keyboard.h"
#include"player.h"
#include"Ghost.h"
#include"Global.h"
#include"Object.h"
#include<iomanip>
#include"Map.h"
#include"Blinky.h"
void update() {
	for (auto i : Global::objects)
		i->update();
}
void render(sf::RenderWindow &window) {
	for (auto i : Global::objects)
		i->render(window);
}
int main()
{
	srand(time(NULL));
	
	Object* player = new Player(32, 32);
	Global::player = (Player*)player;
	Map* map = new Map("Map2.txt");
	Global::map = map;
	Object*ghost =new Blinky(288, 320);	
	Global::objects.push_back(player);
	Global::objects.push_back(ghost);
	 
	sf::RenderWindow window(sf::VideoMode(1200, 650), "SFML works!");
	double changeInSeconds = 0;
	clock_t lastTime=clock();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				keyboard::Right();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				keyboard::Up();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				keyboard::Left();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				keyboard::Down();
			else
				keyboard::clear();
		}		
		
		clock_t now=clock();		
		changeInSeconds += ((double)(now - lastTime)/ CLOCKS_PER_SEC)*60;
		while (changeInSeconds >= 1) {
			update();
			changeInSeconds--;
		}
		lastTime = now;
		window.clear();
		render(window);
		/*sf::RectangleShape rr;
		rr.setPosition(0, 0);
		rr.setSize(sf::Vector2f(300, 300));
		rr.setFillColor(sf::Color::Red);
		window.draw(rr);*/
		window.display();
	}

	return 0;
}
