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

#include "GameEngine.h"
#include <bitmaps/CATlogo.h>

GameEngine GE;

void setup() {
  // put your setup code here, to run once:
  GE.Init("CASASOFT Games");
  GE.Splash(CATlogo, 2000); 
}

void loop() {
  // put your main code here, to run repeatedly:
  GE.Loop();
}
