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

#ifndef SERPENTONEENGINE_H
#define SERPENTONEENGINE_H

#include <MazeGameEngine.h>
#include "SerpentoneScreenLayout.h"

class SerpentoneEngine : public MazeGameEngine
{
  public:
    using MazeGameEngine::MazeGameEngine;

  private:
    Sprite head;
    Sprite tail;	
    virtual void gameStart();
    virtual int gameRun();
    int moveHead();
    void moveTail();
    void initStage();
};
    
#endif
