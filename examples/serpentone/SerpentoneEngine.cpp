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
  initScreenGrid(screenLayout);
  refreshAllScreen();

  head.p.x = 1;
  head.p.y = 0;
  head.lastDir = dirRight;
  Display(head.p, 'Q');

  tail.p.x = 0;
  tail.p.y = 0;
  tail.lastDir = dirRight;
  Display(tail.p, 'R');

  for(int i=0; i<5; i++)
    moveHead();
  delay(200);
}

int SerpentoneEngine::gameRun()
{
  moveHead();
  moveTail();
  delay(100);
  
  if(GU.anyButton()) {
    GameEngine::inGame = 0;

    delay(200);
    return 1;
  }
  else
    return 0;
}

int SerpentoneEngine::moveHead()
{
  if(Read(head.p.Next(head.lastDir)) != '@') {
    if(head.lastDir == dirLeft || head.lastDir == dirRight) {
      if(Read(head.p.Next(dirDown)) == '@')
        head.lastDir = dirDown;
      else if(Read(head.p.Next(dirUp)) == '@')
        head.lastDir = dirUp;
      else
        return -1;
    }
    else {
      if(Read(head.p.Next(dirRight)) == '@')
        head.lastDir = dirRight;
      else if(Read(head.p.Next(dirLeft)) == '@')
        head.lastDir = dirLeft;
      else
        return -1;      
    }
  }

  Display(head.p, 'R');
  head.Move();
  Display(head.p, 'Q');
  return 0;
}

void SerpentoneEngine::moveTail()
{
  if(Read(tail.p.Next(tail.lastDir)) != 'R') {
    if(tail.lastDir == dirLeft || tail.lastDir == dirRight) {
      if(Read(tail.p.Next(dirDown)) == 'R')
        tail.lastDir = dirDown;
      else 
        tail.lastDir = dirUp;
    }
    else {
      if(Read(tail.p.Next(dirRight)) == 'R')
        tail.lastDir = dirRight;
      else 
        tail.lastDir = dirLeft;
    }
  }

  Display(tail.p, '@');
  tail.Move();
}

