// copyright (c) 2017 Roberto Ceccarelli - CasaSoft
// http://strawberryfield.altervista.org 
// 
// This file is part of CasaSoft Arduino Games
// 
// CasaSoft Arduino Games is free software: 
// you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// CasaSoft Arduino Games is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with CasaSoft Arduino Games.  
// If not, see <http://www.gnu.org/licenses/>.

#ifndef MAZEGAMEENGINE_H
#define MAZEGAMEENGINE_H

#include <avr/pgmspace.h>
#include <openGLCD.h>
#include <gameportlib.h>
#include <fonts/System5x7.h>
#include "GameUtils.h"
#include "GameHallOfFame.h"
#include "GameEngine.h"
#include "fonts/SerpentoneFont.h"

#define SCREEN_ROWS 10
#define SCREEN_COLS 21

class MazeGameEngine : public GameEngine
{
  public:
    using GameEngine::GameEngine;

  protected:
	int stageLevel;
	enum gameStates {gameInitStage, gamePlay, gameEndStage, gameOver};
	gameStates gameStatus;
	enum directions {dirRight, dirDown, dirLeft, dirUp};

	class Position
	{
	  public:
		int x;
		int y;
		bool Valid();
		Position Next(directions dir);
	};
	
    class Sprite
	{
      public:		
		Position p;
		directions lastDir;
	    void Move(directions dir);
	    void Move();
	};
	
    char screenGrid[SCREEN_ROWS][SCREEN_COLS];
    void refreshAllScreen();
    void initScreenGrid(char* layout[]);

	void Display(Position p, char c);
	char Read(Position p);
};
    
#endif