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

#include "GameUtils.h"

GameUtils GU;
GamePortLib GP;

void GameUtils::Splash(Image_t bitmap, int timeout)
{
  GLCD.DrawBitmap(bitmap, 0, 0);
  delay(timeout);
  GLCD.ClearScreen();
}

void GameUtils::showHeader(char text[])
{
  GLCD.ClearScreen();
  GLCD.SelectFont(System5x7);
  GLCD.Puts(text);
  GLCD.DrawHLine(0, 9, GLCD.Width);  
}

void GameUtils::showHeader(PGM_P text)
{
  GLCD.ClearScreen();
  GLCD.SelectFont(System5x7);
  GLCD.Puts_P(text);
  GLCD.DrawHLine(0, 9, GLCD.Width);  
}

bool GameUtils::anyButton()
{
  return !GP.ReadButton(0) || !GP.ReadButton(1) || !GP.ReadButton(2) || !GP.ReadButton(3);
}


