#include "EditorState.h"

//Statics

//Intializers
void EditorState::initVariables()
{

}

void EditorState::initBackground()
{

}

void EditorState::initFonts()
{
	if(!this->font.loadFromFile("res/fonts/Dosis-Light.ttf")){
		throw("ERROR::EDITORSTATE::COULD_NOT_LOAD_FONT");
	}
}

void EditorState::initKeybinds()
{
	//Import keybinds from file
	std::ifstream ifs("keymap_editor.ini");

	if(ifs.is_open()){
		std::string key = "";
		std::string key_map = "";

		while(ifs >> key >> key_map){
			this->keybinds[key] = this->supportedKeys->at(key_map);
		}
	}

	ifs.close();
}

void EditorState::initButtons()
{
	
}

//Constructors/Destructors
EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) 
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initButtons();
	this->initKeybinds();
}

EditorState::~EditorState()
{
	auto it = this->buttons.begin();
	for(it = this->buttons.begin(); it != this->buttons.end(); ++it){
		delete it->second;
	}
}

//Functions
void EditorState::updateInput(const float& dt)
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
		this->endState();
}

void EditorState::updateButtons()
{
	/* Update buttons in state and handle functionalities */
	for(auto &it : this->buttons){
		it.second->update(this->mousePosView);
	}
}

void EditorState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for(auto &it : this->buttons){
		it.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target)
{
	if(!target)
		target = this->window;

	this->renderButtons(*target);

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