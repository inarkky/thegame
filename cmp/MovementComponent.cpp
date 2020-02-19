#include "MovementComponent.h"

//Initializers

//Constructor/Destructor
MovementComponent::MovementComponent(
	sf::Sprite& sprite, 
	float maxVelocity,
	float acceleration,
	float deceleration
) : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{

}

//Accessors
const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

//Functions
const bool MovementComponent::idle() const
{
	if(this->velocity.x == 0.f && this->velocity.y == 0.f)
		return true;

	return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
	//Acceleration
	this->velocity.x += this->acceleration * dir_x;
	this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float & dt)
{
	/* Decelerate the sprite and handles max velocity then moves the sprite */

	if(this->velocity.x > 0.f){ //Check for x positive

		//Max velocity check
		if(this->velocity.x > this->maxVelocity)
			this->velocity.x = this->maxVelocity;

		//Decelerate
		this->velocity.x -= deceleration;
		if(this->velocity.x < 0.f)
			this->velocity.x = 0.f;

	}else if(this->velocity.x < 0.f){ //Check for x negative

		//Max velocity check
		if(this->velocity.x < -this->maxVelocity)
			this->velocity.x = -this->maxVelocity;

		//Decelerate
		this->velocity.x += deceleration;
		if(this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}

	if(this->velocity.y > 0.f){ //Check for y positive

		//Max velocity check
		if(this->velocity.y > this->maxVelocity)
			this->velocity.y = this->maxVelocity;

		//Decelerate
		this->velocity.y -= deceleration;
		if(this->velocity.y < 0.f)
			this->velocity.y = 0.f;

	}else if(this->velocity.y < 0.f){ //Check for y negative

		//Max velocity check
		if(this->velocity.y < -this->maxVelocity)
			this->velocity.y = -this->maxVelocity;

		//Decelerate
		this->velocity.y += deceleration;
		if(this->velocity.y > 0.f)
			this->velocity.y = 0.f;

	}

	//Final move
	this->sprite.move(this->velocity * dt);
}