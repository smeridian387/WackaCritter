//includes
//project includes
#include "Critter.h"
#include <cstdlib> //needed for randomness

Critter::Critter()
//initilisation
	:m_sprite()
	,m_texture()
	,m_alive(true)
	,m_deathSound()
	,m_deathBuffer()
	,m_pendingScore(0)
{
	//set up sprite
	m_texture.loadFromFile("graphics/chicken.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width, 
						 rand() % sf::VideoMode::getDesktopMode().height);

	//setup deathsound
	m_deathBuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathSound.setBuffer(m_deathBuffer);


}



void Critter::Draw(sf::RenderTarget& _target)
{
	//only draw sprite if it is alive
	if (m_alive)
	{
		_target.draw(m_sprite);
	}
	

}

//input

void Critter::Input(sf::Event _gameEvent)
{
	if (m_alive)
	{
		//check if this event is a click
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			//did they click on this critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				//they clicked it

				//we die
				m_alive = false;

				//play the deathsound
				m_deathSound.play();

				//add to pending score
				m_pendingScore += 1;
			}
		}
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
};

void Critter::ClearPendingScore() 
{
	m_pendingScore = 0;
}
