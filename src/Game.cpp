#include "Game.h"

//Statics

//Intializers
void Game::initWindow()
{
	/* Creates a SFML window with options from game_config.ini file */
	std::ifstream ifs("game_config.ini");
	this->videoModes = sf::VideoMode::getFullscreenModes();

	//Set defaults
	std::string title = "THEGAME";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;
	unsigned antialising_level = 0;

	if(ifs.is_open()){
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> fullscreen;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
		ifs >> antialising_level;
	}

	ifs.close();

	//Init game window
	this->fullscreen = fullscreen;
	this->windowSettings.antialiasingLevel = antialising_level;
	if(this->fullscreen)
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, windowSettings);
	else
		this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, windowSettings);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys()
{
	//Import keybinds from file
	std::ifstream ifs("keybinds.ini");

	if(ifs.is_open()){
		std::string key = "";
		int value = 0;

		while(ifs >> key >> value){
			this->supportedKeys[key] = value;
		}
	}

	ifs.close();
}

void Game::initStates()
{
	this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
}

//Constructors/Destructors
Game::Game()
{
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game()
{
	delete this->window;

	while(!this->states.empty()){
		delete this->states.top();
		this->states.pop();
	}
}

//Functions
void Game::endApplication()
{
	std::cout << "End Application" << std::endl;
}

void Game::updateDt()
{
	/* Updates dt var with time it takes to update&render 1 frame */
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
	while(this->window->pollEvent(this->sfEvent)){
		if(this->sfEvent.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::update()
{
	this->updateSFMLEvents();

	if(!this->states.empty()){
		this->states.top()->update(this->dt);

		if(this->states.top()->getQuit()){
			this->states.top()->endOfLifeState();
			delete this->states.top();
			this->states.pop();
		}
	}else{ //Application end
		this->endApplication();
		this->window->close();
	}
}

void Game::render()
{
	this->window->clear();

	//render items
	if(!this->states.empty())
		this->states.top()->render(this->window);

	this->window->display();
}

void Game::run()
{
	while(this->window->isOpen()){
		this->updateDt();
		this->update();
		this->render();
	}
}