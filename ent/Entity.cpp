#include "Entity.h"

//Statics

//Intializers
void Entity::initVariables()
{
	this->texture = NULL;
	this->sprite = NULL;

	this->movementComponent = NULL;
}

//Constructors/Destructors
Entity::Entity()
{
	this->initVariables();
}

Entity::~Entity()
{
	delete this->sprite;
	delete this->movementComponent;
}

//Components
void Entity::createSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite = new sf::Sprite(*this->texture);
}	

void Entity::createMovementComponent(const float maxVelocity)
{
	this->movementComponent = new MovementComponent(maxVelocity);
}	

//Functions
void Entity::setPosition(const float x, const float y)
{
	if(this->sprite){
		this->sprite->setPosition(x, y);
	}	
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	if(this->sprite && this->movementComponent){
		this->movementComponent->move(dir_x, dir_y); //Sets velocity
		this->sprite->move(
			this->movementComponent->getVelocity() * dt //Uses velocity
		);
	}
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	if(this->sprite){
		target->draw(*this->sprite);
	}
}