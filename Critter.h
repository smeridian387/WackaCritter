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

	//getter for pending score data
	int GetPendingScore();

	//clear pending score
	void ClearPendingScore();

	//set the ritter type
	void Setup(std::string _textureFile, int _pointValue);


	//end behaviour-------------------------------------

	//Data----------------------------------------------

private:
	
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathSound;
	sf::SoundBuffer m_deathBuffer;
	int m_pendingScore;
	int m_scoreValue;

	//End data----------------------------------------
}; //end Critter class