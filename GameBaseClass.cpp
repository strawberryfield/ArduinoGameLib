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

#include "GameBaseClass.h"

int GameBaseClass::Display()
{
  if(inThis)
    return 1;
    
  inThis = 1;
  GLCD.ClearScreen();
  delay(200);
  return 0;
}

int GameBaseClass::Run()
{
  if(GU.anyButton()) {
    inThis = 0;
    delay(200);
    return 1;
  }
  else
    return 0;
}

