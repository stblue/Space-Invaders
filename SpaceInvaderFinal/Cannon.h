/*create by shaji thorn blue*/
#pragma once
#include "AllSMFLHeader.h"
#include "GameObject.h"

//child class of Gameobject class
class Cannon: public GameObject
{
public:
	Cannon();
	~Cannon();

	float velocity;
	sf::Vector2f moveVelocity;
	void Update();
};