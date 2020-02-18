#include "GameState.h"

//Statics

//Intializers
void GameState::initKeybinds()
{
	//Import keybinds from file
	std::ifstream ifs("keymap_game.ini");

	if(ifs.is_open()){
		std::string key = "";
		std::string key_map = "";

		while(ifs >> key >> key_map){
			this->keybinds[key] = this->supportedKeys->at(key_map);
		}
	}

	ifs.close();
}

void GameState::initTextures()
{
	this->textures["PLAYER_IDLE"].loadFromFile("res/images/sprites/player/bow.png");
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, &this->textures["PLAYER_IDLE"]);
}

//Constructors/Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//Functions
void GameState::updateInput(const float & dt)
{
	//Update player input
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->move(dt, -1.f, 0.f);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->move(dt, 1.f, 0.f);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->move(dt, 0.f, -1.f);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->move(dt, 0.f, 1.f);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if(!target)
		target = this->window;

	this->player->render(target);
}