//includes
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random
#include <ctime> // gives access
#include <string> //gives access to strings
//project includes
#include "Critter.h"




int main()
{
	//game setup-------------------------------------------------------------------

	// render window creation
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "*gameTitleHere*",
		sf::Style::Titlebar | sf::Style::Close);

	//timer functionality
	sf::Clock gameClock;

	//seed our random number generator
	srand(time(NULL));

	//create and instance of our critter class
	const int NUM_CRITTERS = 5;
	Critter critters[NUM_CRITTERS];
	critters[0].Setup("graphics/chicken.png", 10);
	critters[1].Setup("graphics/sloth.png", 5);
	critters[2].Setup("graphics/owl.png", 15);
	critters[3].Setup("graphics/snake.png", 20);
	critters[4].Setup("graphics/moose.png", 25);
	//setup game font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainfont.ttf");

	// score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);

	//end game setup-------------------------------------------------

	//--------------------------------------------------------
	//game loop
	//--------------------------------------------------------------
	while (gameWindow.isOpen())
	{
		//------------------------------------------
		//Input
		//----------------------------------------
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			
			//process inut on critter
			
			for (int i = 0; i < NUM_CRITTERS; ++i)
			{
				critters[i].Input(event);
			}

			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}//end if closed
				
		}//end while(event polling)


		//---------------------------------------------
		//Update
		//----------------------------------------------------
		sf::Time frameTime = gameClock.restart();
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			score += critters[i].GetPendingScore();
			critters[i].ClearPendingScore();
		}
		
		scoreText.setString("Score: " + std::to_string(score));
		//end update
		//

		//----------------------------------------------
		//Draw
		//--------------------------------------------

		//clear the window to a single colour
		gameWindow.clear();

		//draw everything

		
		for (int i = 0; i < NUM_CRITTERS; ++i)
		{
			critters[i].Draw(gameWindow);
		}
		gameWindow.draw(scoreText);
		//display the window contents on screen
		gameWindow.display();

		//end draw
		//--------------------------------------------------
	}
	//end input
	//----------------------------------------------


	//exit point for the program
	return 0;
}//end of main function
