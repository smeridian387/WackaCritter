#pragma once
//includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Critter
{
	//Behaviour----------------------------------------
public:

	//Constructor
	Critter();

	//render the critter to the target
	void Draw(sf::RenderTarget& _target);

	//process input on the critter
	void Input(sf::Event _gameEvent);

	

	//end behaviour-------------------------------------

	//Data----------------------------------------------

private:
	
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;


	//End data----------------------------------------
}; //end Critter class