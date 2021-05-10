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

#define WIDTH  300
#define HEIGHT 300

int main(int argc, char const *argv[])
{
	// Initialize LCGE
	if (lcge_init("res/") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create a window
	int success = lcge_create_context(
		WIDTH, HEIGHT, "LCGE Ninjastar Example", LCGE_NON_RESIZEABLE);

	// Check if there was an error creating the window
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create clock with 60 max fps
	LCGE_clock *clock = lcge_clock_create(60);

	LCGE_image *star1 =
		lcge_image_load("tests/images/ninjastar.png", 0, 0, 100, 100);
	LCGE_image *star2 =
		lcge_image_load("tests/images/ninjastar.png", 200, 0, 100, 100);

	LCGE_image *star3 = lcge_image_load("tests/images/ninjastar.png", 100,
					    100, 100, 100);
	LCGE_image *star4 =
		lcge_image_load("tests/images/ninjastar.png", 0, 200, 100, 100);
	LCGE_image *star5 = lcge_image_load("tests/images/ninjastar.png", 200,
					    200, 100, 100);
	while (lcge_window_is_open()) {
		lcge_image_rotate(star1, 5);
		lcge_image_rotate(star2, 5);
		lcge_image_rotate(star3, 5);
		lcge_image_rotate(star4, 5);
		lcge_image_rotate(star5, 5);
		lcge_window_clear();
		// Do any drawing here
		lcge_image_draw(star1);
		lcge_image_draw(star2);
		lcge_image_draw(star3);
		lcge_image_draw(star4);
		lcge_image_draw(star5);

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}
	lcge_clock_delete(clock);
	lcge_image_delete(star1);
	lcge_image_delete(star2);
	lcge_image_delete(star3);
	lcge_image_delete(star4);
	lcge_image_delete(star5);

	lcge_exit();

	return 0;
}
