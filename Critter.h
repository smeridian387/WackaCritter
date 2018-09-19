#pragma once
//includes
#include <SFML/Graphics.hpp>

class Critter
{
	//Behaviour----------------------------------------
public:

	//Constructor
	Critter();

	//render the critter to the target
	void Draw(sf::RenderTarget& _target);

	//end behaviour-------------------------------------

	//Data----------------------------------------------

private:
	
	sf::Sprite m_sprite;
	sf::Texture m_texture;


	//End data----------------------------------------
}; //end Critter class