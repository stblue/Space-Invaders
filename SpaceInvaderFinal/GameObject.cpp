/*create by shaji thorn blue*/
#include "GameObject.h"


//constructor
GameObject::GameObject()
{
	isLoaded = false;
}

//destructor
GameObject::~GameObject()
{

}

//load texture from given filename if exist
void GameObject::LoadTexture(string filename)
{
	//check if file exist or not
	if (texture.loadFromFile(filename) == false)
	{
		return;
		isLoaded = false;
	}
	else
	{
		sprite.setTexture(texture);
		texture.setSmooth(true);
		isLoaded = true;
	}
}

void GameObject::Draw(sf::RenderWindow &window)
{
	if (isLoaded)
	{
		
		window.draw(sprite);
	}
}

//set position
void GameObject::setPosition(float x, float y)
{
	if (isLoaded)
	sprite.setPosition(x, y);
}

//set scale
void GameObject::setScale(float x, float y)
{
	if (isLoaded)
	sprite.setScale(x, y);
}

//update
void GameObject::Update()
{

}

sf::Vector2f GameObject::getPosition() const
{
	if (isLoaded)
	{
		return sprite.getPosition();
	}
	return sf::Vector2f();
}


float GameObject::getWidth() const 
{
	return sprite.getGlobalBounds().width;
}


float GameObject::getHeight() const
{
	return sprite.getGlobalBounds().height;
}

sf::Rect<float> GameObject::getBoundaryRectangle() const
{

	return sprite.getGlobalBounds();
}
