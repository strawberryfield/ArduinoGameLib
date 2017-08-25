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

#ifndef GAMESTRINGINPUT_H
#define GAMESTRINGINPUT_H

#include <EEPROM.h>
#include <openGLCD.h>
#include <gameportlib.h>
#include <fonts/System5x7.h>
#include "GameUtils.h"
#include "GameBaseClass.h"

// EEPROM constants
#define NAME_START 0

#define NAME_SIZE 13
class GameStringInput : public GameBaseClass
{
  public:
    char UserName[NAME_SIZE];   

    int getFromEEPROM();
    void Display();
    int Run();

  protected:
    int nameCursor;

  private:
    void overwriteChar(uint8_t fgcolor);
};

extern GameStringInput GSI;
#endif
