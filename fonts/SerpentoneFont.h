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

#ifndef SERPENTONEFONT_H
#define SERPENTONEFONT_H

GLCDFONTDECL(SerpentoneFont) = {
    0x0, 0x1, // size of one indicates fixed width no pixel pad font
    6,		// width
    6,		// height
    '@',	// first char (64)
    20,		// char count
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // char '@' space
0x0C, 0x0C, 0x3F, 0x3F, 0x0C, 0x0C, // char 'A' cross
0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, // char 'B' hline
0x00, 0x00, 0x3F, 0x3F, 0x00, 0x00, // char 'C' vline
0x0C, 0x0C, 0x0F, 0x0F, 0x0C, 0x0C, // char 'D' upper cross
0x0C, 0x0C, 0x3C, 0x3C, 0x0C, 0x0C, // char 'E' down cross
0x0C, 0x0C, 0x3F, 0x3F, 0x00, 0x00, // char 'F' left cross
0x00, 0x00, 0x3F, 0x3F, 0x0C, 0x0C, // char 'G' right cross
0x0C, 0x0C, 0x0F, 0x0F, 0x00, 0x00, // char 'H' upper left corner
0x00, 0x00, 0x0F, 0x0F, 0x0C, 0x0C, // char 'I' upper right corner
0x0C, 0x0C, 0x3C, 0x3C, 0x00, 0x00, // char 'J' down left corner
0x00, 0x00, 0x3C, 0x3C, 0x0C, 0x0C, // char 'K' down right corner
0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, // char 'L' upper end
0x00, 0x00, 0x3C, 0x3C, 0x00, 0x00, // char 'M' down end
0x0C, 0x0C, 0x0C, 0x0C, 0x00, 0x00, // char 'N' left end
0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C, // char 'O' right end
0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, // char 'P' dot
0x0C, 0x1E, 0x3F, 0x3F, 0x1E, 0x0C, // char 'Q' head
0x1E, 0x2D, 0x33, 0x33, 0x2D, 0x1E, // char 'R' body
0x00, 0x0C, 0x21, 0x21, 0x0C, 0x00 // char 'S' bonus

};
#endif
