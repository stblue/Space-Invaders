/*create by shaji thorn blue*/
#include "Cannon.h"

//constructor
Cannon::Cannon()
{

}

//destructor
Cannon::~Cannon()
{

}

void Cannon::Update()
{
	//calculating deltaTime for smooth motion
	deltatime = ((float)deltaClock.getElapsedTime().asMicroseconds() - lastframetime) / 1000;
	lastframetime = deltaClock.getElapsedTime().asMilliseconds();
	deltaClock.restart();
	//getting position of the sprite
	sf::Vector2f pos = this->getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveVelocity.x = -1;
		moveVelocity.y = 0;
		if (pos.x > 100)
			sprite.move(moveVelocity*deltatime);
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveVelocity.x = 1;
		moveVelocity.y = 0;
		if (pos.x < 800)
			sprite.move(moveVelocity*deltatime);
	}

}