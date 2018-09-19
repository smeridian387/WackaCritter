//includes
//project includes
#include "Critter.h"

Critter::Critter()
//initilisation
	: m_sprite()
	,m_texture()
{
	//set up sprite
	m_texture.loadFromFile("graphics/chicken.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(300, 300);
}



void Critter::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);

}