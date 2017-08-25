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

#ifndef GAMEUTILS_H
#define GAMEUTILS_H

#include <openGLCD.h>
#include <gameportlib.h>
#include <fonts/System5x7.h>

class GameUtils 
{
  public:
    char Title[20];

    void Splash(Image_t bitmap, int timeout);
    void showHeader(char text[]);
    void showHeader(PGM_P text);
    bool anyButton();  

};

extern GameUtils GU;
extern GamePortLib GP;

#endif
