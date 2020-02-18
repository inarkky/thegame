#ifndef STATE_H
#define STATE_H

#include "../ent/Entity.h"

class State
{
private:
	//variables

	//Initializers
protected:
	//Variables
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::vector<sf::Texture> textures;

	//Initializers
	virtual void initKeybinds() = 0;

public:
	//Constructors/Destructors
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
	virtual ~State();

	//Functions
	const bool& getQuit() const;
	virtual void checkForQuit();

	virtual void endOfLifeState() = 0;
	virtual void updateMousePositions();
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif