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

#include "GameEngine.h"

void GameEngine::Init(char title[])
{
  strcpy(GU.Title, title);
  GLCD.Init();
  GLCD.ClearScreen(); 
  GP.SetPins();
  if(GSI.getFromEEPROM())
    loopStatus = loopMenu;
  else
    loopStatus = loopName;
  MENU.menuInit();  
}

void GameEngine::Splash(Image_t bitmap, int timeout)
{
  GU.Splash(bitmap, timeout);
}

// ---------
// main loop
void GameEngine::Loop()
{
  switch(loopStatus) {
    case loopMenu:
      MENU.menuDisplay();        
      switch(MENU.menuRun()) {
        case MENU.menuStartGame:
          loopStatus = loopGame;
          break;
        case MENU.menuHallOfFame:
          loopStatus = loopHall;
          break;
        case MENU.menuEnterName:
          loopStatus = loopName;
          break;
      }
      break;

    case loopGame:
      if(!inGame)
        gameStart();
      gameRun();
      break;

    case loopHall:
      HALL.Display();
      if(HALL.Run())
        loopStatus = loopMenu;
      break;

    case loopName:
      GSI.Display();
      if(GSI.Run())
        loopStatus = loopMenu;
      break;  
  }
}

// ---------------------
// Game template methods

void GameEngine::gameStart()
{
  inGame = 1;
  GLCD.ClearScreen();
  GLCD.GotoXY(0, 28);
  GLCD.Puts_P(PSTR("Not yet implemented!"));
  delay(200);
}

void GameEngine::gameRun()
{
  if(GU.anyButton()) {
    inGame = 0;
    loopStatus = loopMenu;
    delay(200);
  }
}

