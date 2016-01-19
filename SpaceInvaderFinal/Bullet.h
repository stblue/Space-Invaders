/*created by shaji thorn blue*/
#include "AllSMFLHeader.h"
#include "GameObject.h"

class Bullet :public GameObject
{
public:
	
	Bullet(int bulletBelongsTo);
	~Bullet();
	int bulletBelongsTo = 0; //	1 for cannon 2 for enemy
	void Update();
	int Move();

private:
	sf::Vector2f moveDirection;
	void checkForCollision();
};
