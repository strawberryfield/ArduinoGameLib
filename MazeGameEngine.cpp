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

void MazeGameEngine::Init(char title[], char* layout[])
{
  initScreenGrid(layout);
  GameEngine::Init(title);
}


void MazeGameEngine::refreshAllScreen()
{
  GLCD.ClearScreen();
  GLCD.SelectFont(SerpentoneFont);
  for(int x=0; x < SCREEN_COLS; x++)
    for(int y=0; y < SCREEN_ROWS; y++) {
      GLCD.GotoXY(x*6+1, y*6+2);
      GLCD.PutChar(screenGrid[y][x]);
    }
    GLCD.DrawRect(0, 0, GLCD.Width, GLCD.Height);    
}

void MazeGameEngine::initScreenGrid(char* layout[])
{
  for(int y=0; y<SCREEN_ROWS; y++) {
    strncpy_P(screenGrid[y], (char*)pgm_read_word(&(layout[y])), SCREEN_COLS);  
  }
}
