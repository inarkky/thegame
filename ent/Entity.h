#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/System.hpp> 
#include <SFML/Window.hpp> 
#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp> 
#include <SFML/Network.hpp> 

class Entity
{
private:
	//Variables

	//Initializers
protected:
	//Variables
	sf::RectangleShape shape;
	float movementSpeed;

	//Initializers
	
public:
	//Constructors/Destructors
	Entity();
	virtual ~Entity();

	//Functions
	virtual void move(const float& dt, const float x, const float y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);
};


#endif