/*create by shaji thorn blue*/
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <list>
#include "Cannon.h"
#include "Aliens.h"
#include "Bullet.h"

int main()
{
	
	//setting alien position
	float alienposx = 100;
	float alienposy = 100;
	float aliensdiffx = 100;
	float aliensdiffy = 50;
	int downMovement = 0;
	int score = 0, died = 0;
	sf::Text scoreText;
	sf::Clock clock;
	//player bullet
	std::vector<Bullet> bullet;
	//alien bullet
	std::list<Bullet> bulletListEnemy;

	//Font for text
	sf::Font font;
	if (!font.loadFromFile("space.ttf"))
	{
		// error...
	}
	


	//initialize score text
	scoreText.setFont(font);
	scoreText.setCharacterSize(24); 
	scoreText.setColor(sf::Color::Green);
	scoreText.setStyle(sf::Text::Bold);



	//initialize game window
	sf::RenderWindow window(sf::VideoMode(1024, 786), "Space Invader EA Native");
	
	
	//creating cannon
	Cannon *cannon = new Cannon();
	cannon->LoadTexture("Cannon.png");
	cannon->setPosition((1024 / 2) - 100, 700);
	cannon->setScale(0.5, 0.25);

	Aliens *aliens[5][11];

	//generating aliens on the display
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			aliens[i][j] = new Aliens();
			switch (i)
			{
			case 0:
				aliens[i][j]->LoadTexture("AlienType0.png");
				break;
			case 1:
				aliens[i][j]->LoadTexture("AlienType1.png");
				break;
			case 2:
				aliens[i][j]->LoadTexture("AlienType1.png");
				break;
			case 3:
				aliens[i][j]->LoadTexture("AlienType2.png");
				break;
			case 4:
				aliens[i][j]->LoadTexture("AlienType2.png");
				break;
			}
			aliens[i][j]->setPosition((alienposx + aliensdiffx), alienposy);
			aliens[i][j]->setScale(0.40, 0.40);
			alienposx += 60;	
		}
		alienposx = 100;
		alienposy += 60;
	}

	//======================================================================================================
	//act as game loop
	while (window.isOpen())
	{
		sf::Time elasped = clock.getElapsedTime();
		if (elasped.asSeconds() >2)
		{
			int col = rand() % 11;
			int row = -1;
			for (int j = 0; j < 5; j++)
			{
				if (aliens[j][col] == NULL)
					continue;
				else
					row = j;
			}

			if (row != -1)
			{
				bulletListEnemy.push_back(Bullet(2));
				bulletListEnemy.back().LoadTexture("Bullet.png");
				bulletListEnemy.back().setPosition(aliens[row][col]->getPosition().x + aliens[row][col]->getBoundaryRectangle().width / 2, aliens[row][col]->getPosition().y + 40);
				bulletListEnemy.back().setScale(0.25, 0.25);
			}
			

			clock.restart();
		}
		//get events from the display
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		//check if space key is pressed if yes then fire one bullet
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (bullet.size() == 0)
			{
				bullet.push_back(Bullet(1));
				bullet.back().LoadTexture("Bullet.png");
				bullet.back().setPosition(cannon->getPosition().x+cannon->getBoundaryRectangle().width/2 , cannon->getPosition().y);
				bullet.back().setScale(0.25, 0.25);
			}
				
		}

		//check if keyboard is pressed, if yes move cannon
		if (sf::Keyboard::isKeyPressed)
		{
				cannon->Update();		
		}

		

		window.clear();

		//drawing checking collision====================================================================
		//cannon drawing
		cannon->Draw(window);
		

		//aliens drawing and movement 
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				if (aliens[i][j] == NULL)
				{
					continue;
				}
				else 
				{
					aliens[i][j]->Draw(window);
					downMovement = aliens[i][j]->moveLeftRight();

					if (downMovement == 1)
					{
						for (int i = 0; i < 5; i++)
						{
							for (int j = 0; j < 11; j++)
							{
								if (aliens[i][j] != NULL)
								{
									aliens[i][j]->moveDown(20);
								}
								
							}
						}
						downMovement = 0;
					}
				}
			}
		}
		
		
		//draw bullet on scren
		for (int i = 0; i < bullet.size(); i++)
		{
			bullet[i].Draw(window);
			int j = bullet[i].Move();
			if (j == 2)
			{
				bullet.clear();
			}

			//check for collision
				for (int k = 0; k < 5; k++)
				{
					for (int j = 0	; j < 11; j++)
					{
						if (aliens[k][j] != NULL)
						{
							if (bullet[i].getBoundaryRectangle().intersects(aliens[k][j]->getBoundaryRectangle()))
							{
								bullet.clear();
								delete(aliens[k][j]);
								aliens[k][j] = NULL;
								switch (k)
								{
								case 0: score += 40;
										break;
								case 1:score += 20;
										break;
								case 2:score += 20;
										break;
								case 3:score += 10;
										break;
								case 4:score += 10;
										break;
								default:
									break;
								}
								break;
							}
						}
						
					}
				}
		}

		for (std::list<Bullet>::iterator itr = bulletListEnemy.begin(); itr != bulletListEnemy.end(); itr++)
		{
			(*itr).Draw(window);
			int j = (*itr).Move();
			if (j == 2)
			{
				itr = bulletListEnemy.erase(itr);
			}
			else if ((*itr).getBoundaryRectangle().intersects(cannon->getBoundaryRectangle()))
			{
				itr = bulletListEnemy.erase(itr);
				died++;
			}
		}

		
		//showing score
		std::string scorestr = std::to_string(score);
		std::string diedstr = std::to_string(died);
		scoreText.setString("Score: "+scorestr+"  Died: "+diedstr);
		window.draw(scoreText);
		//drawing checking collision====================================================================
		window.display();
	}
	
	return 0;
}

