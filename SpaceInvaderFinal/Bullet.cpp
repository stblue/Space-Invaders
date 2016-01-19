/*created by shaji thorn blue*/
#include "Bullet.h"

//constructor
Bullet::Bullet(int bulletBelongsTo)
{
	this->bulletBelongsTo = bulletBelongsTo; // 1 for cannon 2 for enemy
	switch (bulletBelongsTo)
	{ 
	case 1:
		moveDirection = sf::Vector2f(0, -1);
		break; 
	case 2:
		moveDirection = sf::Vector2f(0, 1);
		break;
	default:
		break;
	}
}

Bullet::~Bullet()
{
	
}

//movement
int Bullet::Move()
{
	//calculating deltaTime for smooth motion
	deltatime = ((float)deltaClock.getElapsedTime().asMicroseconds() - lastframetime) / 1000;
	lastframetime = deltaClock.getElapsedTime().asMilliseconds();
	deltaClock.restart();

	sprite.move(0,moveDirection.y *deltatime* 0.5);

	if (sprite.getPosition().y < 0 || sprite.getPosition().y > 800)
	{
		return 2; //tell it time to destroy the bullet game object
	}

	return 1;
}

void Bullet::Update()
{
	
}