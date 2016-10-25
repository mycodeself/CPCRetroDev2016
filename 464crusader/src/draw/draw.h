/*	
 *
 *  This file is part of 464 Crusader, game for Amstrad CPC 464.
 *
 *  464 Crusader is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  464 Crusader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with 464 Crusader.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _DRAW_H_
#define _DRAW_H_

#include "../common.h"

void drawEntity(Entity*) __z88dk_fastcall;
void eraseEntityTileBox(Entity*) __z88dk_fastcall;
void eraseEntitySolidBox(Entity*) __z88dk_fastcall;
void updateDrawableEntity(Entity*) __z88dk_fastcall;
void eraseEntityBuffersSolidBox(Entity*);
void drawMap();

#endif