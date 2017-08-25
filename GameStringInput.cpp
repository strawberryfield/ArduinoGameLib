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

#include "GameStringInput.h"

GameStringInput GSI;

int GameStringInput::getFromEEPROM()
{
  EEPROM.get(NAME_START, UserName);

  if(UserName[0] >= 'A' && UserName[0] <= 'Z')
    return 1;
  else {
    for(int j=0; j<NAME_SIZE-1; j++)
      UserName[j] = ' ';
    UserName[12] = 0;
    return 0;    
  }
}

void GameStringInput::Display()
{
  if(inThis)
    return;
    
  inThis = 1;
  GU.showHeader(PSTR("Enter your name:"));

  nameCursor = 0;  
  overwriteChar(WHITE);
  for(int j=1; j<NAME_SIZE-1; j++) {
    nameCursor = j;
    overwriteChar(BLACK);
  }
  nameCursor = 0;
}

int GameStringInput::Run()
{
  int z = GP.ReadDigital(Y1);
  if(z == DIRECTION_UP) {
    UserName[nameCursor]++;
    if(UserName[nameCursor] == 33)
      UserName[nameCursor] = 65;
    else if(UserName[nameCursor] == 91)  
      UserName[nameCursor] = 32;
    overwriteChar(WHITE);
  }
  else if(z == DIRECTION_DOWN) {
    UserName[nameCursor]--;
    if(UserName[nameCursor] == 31)
      UserName[nameCursor] = 90;
    else if(UserName[nameCursor] == 64)  
      UserName[nameCursor] = 32;
    overwriteChar(WHITE);
  }

  z = GP.ReadDigital(X1);
  if(z == DIRECTION_LEFT && nameCursor > 0) {
    overwriteChar(BLACK);
    nameCursor--;
    overwriteChar(WHITE);
  }
  else if(z == DIRECTION_RIGHT && nameCursor < NAME_SIZE-2) {
    overwriteChar(BLACK);
    nameCursor++;
    overwriteChar(WHITE);    
  }
  
  if(GU.anyButton()) {
    EEPROM.put(NAME_START, UserName);
    inThis = 0;
    delay(200);
    return 1;
  }
  else 
    return 0;
}

void GameStringInput::overwriteChar(uint8_t fgcolor = BLACK)
{
  GLCD.GotoXY(nameCursor * 7+1, 28);
  GLCD.SelectFont(System5x7, fgcolor);
  GLCD.PutChar(UserName[nameCursor]);
  GLCD.DrawHLine(nameCursor * 7, 27, 7, fgcolor == WHITE ? PIXEL_ON : PIXEL_OFF);
  GLCD.DrawVLine(nameCursor * 7, 28, 8, fgcolor == WHITE ? PIXEL_ON : PIXEL_OFF);
 
  delay(200);
}

