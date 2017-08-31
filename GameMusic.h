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

#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H

#include <Arduino.h>
#include "pitches.h"

#define TONE_PIN	2

class GameMusic 
{
  public:
    int size = 8;
	int melody[8] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
	// note durations: 4 = quarter note, 8 = eighth note, etc.:
	int noteDurations[8] = {  4, 8, 8, 4, 4, 4, 4, 4};
	
    void Play();  
};

#endif
