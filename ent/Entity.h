#ifndef ENTITY_H
#define ENTITY_H

#include "../cmp/MovementComponent.h"

class Entity
{
private:
	//Variables

	//Initializers
	void initVariables();

protected:
	//Variables
	sf::Sprite sprite; 

	MovementComponent* movementComponent;

	//Initializers
	
public:
	//Constructors/Destructors
	Entity();
	virtual ~Entity();

	//Components
	void setTexture(sf::Texture& texture);
	void createMovementComponent(const float maxVelocity);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float& dt, const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};


#endif