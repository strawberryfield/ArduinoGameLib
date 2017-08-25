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

#include "GameMenu.h"

void GameMenu::menuInit()
{
  menuStatus = menuNone;  
}

void GameMenu::menuDisplay()
{
  if(menuStatus != menuNone)
    return;
    
  GU.showHeader(GU.Title);  
  menuIconSelected(0);
  GLCD.GotoXY(MENU_TEXT_LEFT, MENU_ICON_TOP+1);
  GLCD.Puts_P(PSTR("Start Game"));

  menuIconUnselected(1);
  GLCD.GotoXY(MENU_TEXT_LEFT, MENU_ICON_TOP+1+MENU_VERT_SPACE);
  GLCD.Puts_P(PSTR("Hall of Fame"));

  menuIconUnselected(2);
  GLCD.GotoXY(MENU_TEXT_LEFT, MENU_ICON_TOP+1+MENU_VERT_SPACE*2);
  GLCD.Puts_P(PSTR("Enter your name"));

  menuStatus = menuStartGame;
}

GameMenu::menuStates GameMenu::menuRun()
{
   int y = GP.ReadDigital(Y1);
   if(y == DIRECTION_UP && menuStatus > 1) {
     int current = static_cast<int>(menuStatus) - 1;
     menuIconUnselected(current);
     menuIconSelected(current - 1);
     menuStatus = static_cast<menuStates>(current);
     delay(200);
   }
   else if(y == DIRECTION_DOWN && menuStatus < 3) {
     int current = static_cast<int>(menuStatus);
     menuIconUnselected(current - 1);
     menuIconSelected(current);
     menuStatus = static_cast<menuStates>(current+1);
     delay(200);
   }
   
   if(GU.anyButton()) {
     menuStates ret = menuStatus; 
     menuStatus = menuNone;
     return ret;
   }
   else
     return menuNone; 
}

// ---------------
// Private methods

void GameMenu::menuIconUnselected(int row)
{
  GLCD.DrawBitmap(CircleEmpty, MENU_ICON_LEFT, MENU_ICON_TOP + MENU_VERT_SPACE * row);
}

void GameMenu::menuIconSelected(int row)
{
  GLCD.DrawBitmap(CircleFilled, MENU_ICON_LEFT, MENU_ICON_TOP + MENU_VERT_SPACE * row);
}


