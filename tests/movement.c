/*
    LCGE - A Lightweight C Game Engine
    Copyright (C) 2021  Satvik Reddy

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA

    Satvik Reddy <reddy.satvik@gmail.com>
*/

#include <LCGE/lcge.h>

int main(int argc, char const *argv[])
{
	// Initialize LCGE
	if (lcge_init("res/") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create a window
	int success = lcge_create_context(800, 800, "LCGE Movement Example",
					  LCGE_NON_RESIZEABLE);

	// Create clock with 60 max fps
	LCGE_clock *clock = lcge_clock_create(60);

	// Check if there was an error creating the window
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	float x = 50;
	float inc = 10.0f;
	LCGE_rect *rect = lcge_rect_load(50, 325, 150, 200);

	float width = lcge_rect_get_width(rect);
	float height = lcge_rect_get_height(rect);

	while (lcge_window_is_open()) {
		// update
		x += inc;

		// Reverse the rectangle once it hits the edge of the window
		if ((x + width) > 800 || x < 0)
			inc = -1.0f * inc;
		lcge_rect_set(rect, x, lcge_rect_get_y(rect), width, height);

		// draw
		lcge_window_clear();
		lcge_rect_draw(rect, 108, 92, 231);

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}

	lcge_rect_delete(rect);
	lcge_clock_delete(clock);

	lcge_exit();

	return 0;
}
