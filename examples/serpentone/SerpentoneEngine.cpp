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

int SerpentoneEngine::gameRun()
{
  switch(gameStatus) {
    case gameInitStage:
      initStage();
      gameStatus = gamePlay;
      break;

    case gamePlay:
      moveHead();
      moveTail();
      delay(100);
      
      if(GU.anyButton()) 
        gameStatus = gameOver;
      break;  

    case gameOver:
      GU.showHeader();
      GLCD.GotoXY(36,30);
      GLCD.Puts_P(PSTR("GAME OVER"));
      GameEngine::inGame = 0; 
      delay(2000);
      return 1;
      break;
  }
  return 0;
}

void SerpentoneEngine::initStage()
{
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

  for(int i=0; i<(5+2*stageLevel); i++) {
    int pos;
    int r;
    int c;
    do {
      pos = random(SCREEN_COLS*SCREEN_ROWS);
      r = pos / SCREEN_COLS;
      c = pos % SCREEN_COLS;      
    } while(screenGrid[r][c] != EMPTY_CELL);
    Display(c, r, BONUS_CELL);
  }

  song.Play();
}

int SerpentoneEngine::moveHead()
{
  char cell;
  int ret = 0;
  
  int d = GP.ReadDigital(X1);
  if(d != DIRECTION_NONE) {
    if( d == DIRECTION_LEFT) {
      testHead(dirLeft);
    }
    else {
      testHead(dirRight);      
    }
  }

  d = GP.ReadDigital(Y1);
  if(d != DIRECTION_NONE) {
    if( d == DIRECTION_UP) {
      testHead(dirUp);
    }
    else {
      testHead(dirDown);      
    }
  }

  
  if(!testHead()) {
    if(head.lastDir == dirLeft || head.lastDir == dirRight) {
      if(!testHead(dirDown))
        if(!testHead(dirUp))
          return -1;
    }
    else {
      if(!testHead(dirLeft))
        if(!testHead(dirRight))
          return -1;
    }
  }

  Display(head.p, 'R');
  head.Move();
  Display(head.p, 'Q');
  return ret;
}

bool SerpentoneEngine::testHead(MazeGameEngine::directions dir) 
{
  char r = Read(head.p.Next(dir));
  if(r == EMPTY_CELL || r == BONUS_CELL) {
    head.lastDir = dir;
    return 1;
  }
  else
    return 0;
}

bool SerpentoneEngine::testHead() 
{
  return testHead(head.lastDir);
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

