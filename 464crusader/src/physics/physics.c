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
#include "physics.h"

const Collision _col = {
	{0, 0}, {0, 0},
	{0, 0}, {0, 0},
	0
};

void
checkCollision(Collision* c)
{
  if((c->x[0] + c->w[0]) < c->x[1] || c->x[0] > (c->x[1] + c->w[1]))
  	c->collision = 0;
  else if((c->y[0] + c->h[0]) < c->y[1] || c->y[0] > (c->y[1] + c->h[1]))
    c->collision = 0;
  else c->collision = 1;
}