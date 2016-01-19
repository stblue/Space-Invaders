/*create by shaji thorn blue*/
#pragma once
#include "AllSMFLHeader.h"
using namespace std;
using namespace sf;
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	Texture texture;
	bool isLoaded;
	sf::Sprite sprite;
	sf::Clock deltaClock;
	float deltatime;
	int lastframetime = 0;
	virtual void LoadTexture(string std);
	virtual void Draw(sf::RenderWindow &window);
	virtual void setPosition(float x, float y);
	virtual void setScale(float x, float y);
	virtual void Update();
	sf::Vector2f GameObject::getPosition() const;

	//variables for collision detection
	virtual float getWidth() const;
	virtual float getHeight() const;
	virtual sf::Rect<float> getBoundaryRectangle() const;
};