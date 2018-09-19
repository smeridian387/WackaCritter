//includes
//project includes
#include "Critter.h"
#include <cstdlib> //needed for randomness

Critter::Critter()
//initilisation
	: m_sprite()
	,m_texture()
{
	//set up sprite
	m_texture.loadFromFile("graphics/chicken.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, 
						 rand() % sf::VideoMode::getDesktopMode().height);
}



void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);

}