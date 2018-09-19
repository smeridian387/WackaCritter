//includes
#include <SFML/Graphics.hpp>
#include <cstdlib> //gives access to random
#include <ctime> // gives access
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
		//end update
		//

		//----------------------------------------------
		//Draw
		//--------------------------------------------

		//clear the window to a single colour
		gameWindow.clear();

		//draw everything

		myCritter.Draw(gameWindow);

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
