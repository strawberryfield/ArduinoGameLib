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

#include "GameHallOfFame.h"

void GameHallOfFame::Display()
{
  if(GameBaseClass::Display())
    return;
    
  GLCD.GotoXY(0, 28);
  GLCD.Puts_P(PSTR("Not yet implemented!"));
}

void GameHallOfFame::AddScore(unsigned int newScore)
{
  if(items[HALL_ITEMS-1].score > newScore)
    return;
    
  strcpy(items[HALL_ITEMS-1].name, GSI.UserName);
  items[HALL_ITEMS-1].score = newScore;
}

