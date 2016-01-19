/*create by shaji thorn blue*/
#pragma once
#include "GameObject.h"
#include "AllSMFLHeader.h"

class Aliens: public GameObject
{
public:
	Aliens();
	~Aliens();

	int moveLeftRight();
	void moveDown(int value);
	void Update();
	static sf::Vector2f moveDir;
	static int numberOfAlien;
	int down;
};
