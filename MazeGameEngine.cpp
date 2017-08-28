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

#include "MazeGameEngine.h"


void MazeGameEngine::refreshAllScreen()
{
  GLCD.ClearScreen();
  GLCD.SelectFont(SerpentoneFont);
  GLCD.DrawRect(0, 0, GLCD.Width, GLCD.Height);    
  for(int x=0; x < SCREEN_COLS; x++)
    for(int y=0; y < SCREEN_ROWS; y++) {
      GLCD.GotoXY(x*6+1, y*6+2);
      GLCD.PutChar(screenGrid[y][x]);
    }
}

void MazeGameEngine::initScreenGrid(char* layout[])
{
  for(int y=0; y<SCREEN_ROWS; y++) {
    strncpy_P(screenGrid[y], (char*)pgm_read_word(&(layout[y])), SCREEN_COLS);  
  }
}


void MazeGameEngine::Display(MazeGameEngine::Position p, char c)
{
  GLCD.GotoXY(p.x * 6 +1, p.y *6 +2);
  GLCD.PutChar(c);
  screenGrid[p.y][p.x] = c;
}

bool MazeGameEngine::Position::Valid()
{
  return x >= 0 && x < SCREEN_COLS && y >= 0 && y < SCREEN_ROWS;
}

MazeGameEngine::Position MazeGameEngine::Position::Next(MazeGameEngine::directions dir)
{
  Position ret;
  ret.x = x;
  ret.y = y;  
  switch(dir) {
	case dirRight:
	  ret.x++;
	  break;
	case dirLeft:
	  ret.x--;
	  break;
	case dirDown:
	  ret.y++;
	  break;
	case dirUp:
	  ret.y--;
	  break;
  }
  return ret;
}

void MazeGameEngine::Sprite::Move(MazeGameEngine::directions dir)
{
  p = p.Next(dir);
  lastDir = dir;
}

void MazeGameEngine::Sprite::Move()
{
  MazeGameEngine::Sprite::Move(lastDir);
}


char MazeGameEngine::Read(MazeGameEngine::Position p)
{
  if(p.Valid())	
    return screenGrid[p.y][p.x];	
  else
	return 0;
}