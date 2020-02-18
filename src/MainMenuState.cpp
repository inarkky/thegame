#include "MainMenuState.h"

//Statics

//Intializers
void MainMenuState::initVariables()
{

}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x), 
			static_cast<float>(this->window->getSize().y)
		)
	);

	if(!this->backgroundTexture.loadFromFile("res/images/backgrounds/bg1.png")){
		throw("ERROR::MAINMENUSTATE::FAILED_TO_LOAD_BG_TEXTURE");
	}
	this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if(!this->font.loadFromFile("res/fonts/BreatheFire.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(600, 375, 150, 50, 
		&this->font, "New Game", 
		sf::Color(100, 100, 100, 200), 
		sf::Color(150, 150, 150, 255), 
		sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS"] = new Button(600, 450, 150, 50, 
		&this->font, "Settings", 
		sf::Color(100, 100, 100, 200), 
		sf::Color(150, 150, 150, 255), 
		sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(600, 525, 150, 50, 
		&this->font, "Quit", 
		sf::Color(100, 100, 100, 200), 
		sf::Color(150, 150, 150, 255), 
		sf::Color(20, 20, 20, 200));

}


void MainMenuState::initKeybinds()
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

//Constructors/Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) : State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->initKeybinds();
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
}

//Functions
void MainMenuState::endOfLifeState()
{
	std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();
}

void MainMenuState::updateButtons()
{
	/* Update buttons in state and handle functionalities */
	for(auto &it : this->buttons){
		it.second->update(this->mousePosView);
	}

	//Start ew game
	if(this->buttons["GAME_STATE"]->isPressed()){
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));
	}

	//Quit game
	if(this->buttons["EXIT_STATE"]->isPressed()){
		this->quit = true;
	}
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for(auto &it : this->buttons){
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if(!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);

	//DEBUGGING - print coordinates at mousepoint
	//sf::Text mouseText;
	//mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	//mouseText.setFont(this->font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << this->mousePosView.x << " " << mousePosView.y;
	//mouseText.setString(ss.str());
	//target->draw(mouseText);
}