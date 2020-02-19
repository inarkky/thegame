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
	void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);

	//Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const float x, const float y, const float& dt);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};


#endif