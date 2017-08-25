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

#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <openGLCD.h>
#include <gameportlib.h>
#include <fonts/System5x7.h>
#include <bitmaps/CircleEmpty.h>
#include <bitmaps/CircleFilled.h>
#include "GameUtils.h"

// Menu constants
#define MENU_ICON_LEFT    5
#define MENU_ICON_TOP     13
#define MENU_TEXT_LEFT    16
#define MENU_VERT_SPACE   12

class GameMenu 
{
  public:
    enum menuStates {menuNone, menuStartGame, menuHallOfFame, menuEnterName};

    void menuInit();
    void menuDisplay();
    menuStates menuRun();

  protected:
    char Title[20];
    
    menuStates menuStatus;
    
  private:
    void menuIconUnselected(int row);
    void menuIconSelected(int row);
};
    
#endif
