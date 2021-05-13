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
#include <stdio.h>

#define WIDTH  800
#define HEIGHT 800

int main(int argc, char const *argv[])
{
	// Initialize LCGE
	if (lcge_init("res/") == LCGE_INIT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create a window
	int success = lcge_create_context(WIDTH, HEIGHT, "LCGE Mouse Example",
					  LCGE_NON_RESIZEABLE);

	// Check if there was an error creating the window
	if (success == LCGE_CONTEXT_ERR) {
		lcge_exit();
		return -1;
	}

	// Create clock with 60 max fps
	LCGE_clock *clock = lcge_clock_create(60);

	char count_text[50];
	int count = 0;
	sprintf(count_text, "Clicks: %d", count);

	LCGE_font *font =
		lcge_font_load("tests/fonts/VT323-Regular.ttf", 72.0f);
	LCGE_text *text = lcge_text_load(count_text, 0, 0, font);

	float width = lcge_text_get_width(text);
	float height = lcge_text_get_height(text);

	// Center text on the screen
	lcge_text_set(text, count_text, (WIDTH - width) / 2,
		      (HEIGHT - height) / 2 + height);

	while (lcge_window_is_open()) {
		// Update
		if (lcge_get_mouse_button(LCGE_MOUSE_BUTTON_LEFT) ==
		    LCGE_MOUSE_BUTTON_PRESSED) {
			sprintf(count_text, "Clicks: %d", ++count);
		}

		lcge_text_set(text, count_text, (WIDTH - width) / 2,
			      (HEIGHT - height) / 2 + height);

		// Do any drawing here
		lcge_window_clear();
		lcge_text_draw(text, 255, 255, 255);

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}
	lcge_clock_delete(clock);
	lcge_text_delete(text);
	lcge_font_delete(font);

	lcge_exit();

	return 0;
}
