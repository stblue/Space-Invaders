/*create by shaji thorn blue*/
#include "Aliens.h"

Aliens::Aliens()
{
	numberOfAlien += 1;
}

Aliens::~Aliens()
{

}

int Aliens::moveLeftRight()
{
	//calculating deltaTime for smooth motion
	deltatime = ((float)deltaClock.getElapsedTime().asMicroseconds() - lastframetime) / 1000;
	lastframetime = deltaClock.getElapsedTime().asMilliseconds();
	deltaClock.restart();

	int returnvalue = -1;
	if (Aliens::moveDir.y > 0)
	{
		Aliens::moveDir.y = 0;
	}

		//getting position of the sprite
		sf::Vector2f pos = this->getPosition();
		
		
		if (pos.x < 50)
		{
			Aliens::moveDir.x = 1;
		}

		else if (pos.x > 950 )
		{
			Aliens::moveDir.x = -1;
			returnvalue = 1;//implies dowm all of them by one 
		}

		sprite.move(Aliens::moveDir.x*deltatime*0.1, 0);
		return returnvalue;
}

void Aliens::moveDown(int value)
{
	//calculating deltaTime for smooth motion
	deltatime = ((float)deltaClock.getElapsedTime().asMicroseconds() - lastframetime) / 1000;
	lastframetime = deltaClock.getElapsedTime().asMilliseconds();
	deltaClock.restart();
	sprite.move(0,value*deltatime );
}

void Aliens::Update()
{

}

//declaring static variable
sf::Vector2f Aliens::moveDir = sf::Vector2f(-1,0);
int Aliens::numberOfAlien = 0;