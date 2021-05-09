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

#define SPRITE_WIDTH 326.0f
#define SPRITE_HEIGHT 296.0f

int main(int argc, char const *argv[])
{
	// Initialize LCGE
	if (lcge_init("res/") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create a window
	int success = lcge_create_context(1000, 800, "LCGE Image Example",
					  LCGE_NON_RESIZEABLE);

	// Create clock with 60 max fps
	LCGE_clock *clock = lcge_clock_create(60);

	// Check if there was an error creating the window
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	// Load image_one
	LCGE_image *image_one =
		lcge_image_load("tests/images/player_sprite.png", 100, 100,
				SPRITE_WIDTH * 0.8f, SPRITE_HEIGHT * 0.8f);

	// Load image_two
	LCGE_image *image_two =
		lcge_image_load("tests/images/player_sprite.png", 500, 300,
				SPRITE_HEIGHT * 1.5, SPRITE_HEIGHT * 1.5);
	while (lcge_window_is_open()) {
		lcge_window_clear();
		// Do any drawing here
		lcge_image_draw(image_one);
		lcge_image_draw(image_two);

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}

	// clean up
	lcge_image_delete(image_one);
	lcge_image_delete(image_two);

	lcge_clock_delete(clock);

	lcge_exit();

	return 0;
}
