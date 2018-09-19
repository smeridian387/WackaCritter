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
	Critter myCritter;

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
				myCritter.Input(event);
			
			



			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}//end if closed
				
		}//end while(event polling)


		//---------------------------------------------
		//Update
		//----------------------------------------------------
		sf::Time frameTime = gameClock.restart();
		score += myCritter.GetPendingScore();
		myCritter.ClearPendingScore();
		scoreText.setString("Score: " + std::to_string(score));
		//end update
		//

		//----------------------------------------------
		//Draw
		//--------------------------------------------

		//clear the window to a single colour
		gameWindow.clear();

		//draw everything

		myCritter.Draw(gameWindow);
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
