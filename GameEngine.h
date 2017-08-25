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

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <openGLCD.h>
#include <gameportlib.h>
#include <fonts/System5x7.h>
#include "GameUtils.h"
#include "GameStringInput.h"
#include "GameMenu.h"
#include "GameHallOfFame.h"

class GameEngine 
{
  public:
    void Init(char title[]);
    void Splash(Image_t bitmap, int timeout=2000);
    void Loop();

  protected:
    GameMenu  MENU;
    GameHallOfFame HALL;
    
    enum loopStates {loopMenu, loopGame, loopHall, loopName};
    
    loopStates loopStatus;
    bool inGame;
    
    virtual void gameStart();
    virtual void gameRun();
};
    
#endif
