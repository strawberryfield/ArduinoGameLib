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

#ifndef GAMEHALLOFFAME_H
#define GAMEHALLOFFAME_H

#include <openGLCD.h>
#include <fonts/System5x7.h>
#include "GameUtils.h"
#include "GameStringInput.h"
#include "GameBaseClass.h"

// EEPROM constants
#define HALL_START 13
#define HALL_ITEMS 5

struct HallItem 
{
  public:
    char name[NAME_SIZE];
    unsigned int score; 
};

class GameHallOfFame : public GameBaseClass
{
  public:  
    void Display();
    void AddScore(unsigned int newScore);

  protected:
    HallItem items[HALL_ITEMS];
};

#endif
