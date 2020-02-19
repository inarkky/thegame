#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"


class Player : public Entity
{
private:
	//Variables

	//Initializer
	void initVariables();
	void initComponents();
	
public:
	//Constructors/Destructors
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();

	//Components

	//Functions
	virtual void update(const float& dt);
};


#endif