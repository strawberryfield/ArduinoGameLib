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

#include "SerpentoneEngine.h"

void SerpentoneEngine::gameStart()
{
  if(inGame)
    return;

  inGame = 1;
  GLCD.ClearScreen();
  GLCD.GotoXY(0, 28);
  GLCD.Puts_P(PSTR("Not yet implemented!"));
  delay(200);
}

int SerpentoneEngine::gameRun()
{
  if(GU.anyButton()) {
    GameEngine::inGame = 0;
    delay(200);
    return 1;
  }
  else
    return 0;
}

