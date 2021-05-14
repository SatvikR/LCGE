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

	char pos_text[50];
	char clicks_text[50];

	sprintf(pos_text, "Cursor Pos: %g, %g", 100.0f, 100.0f);
	sprintf(clicks_text, "Clicks: %d", 1000);

	int clicks = 0;

	LCGE_font *font =
		lcge_font_load("tests/fonts/VT323-Regular.ttf", 32.0f);

	LCGE_text *pos_text_obj = lcge_text_load(pos_text, 0, 0, font);
	LCGE_text *clicks_text_obj = lcge_text_load(clicks_text, 0, 0, font);

	float width = lcge_text_get_width(pos_text_obj);
	float height = lcge_text_get_height(pos_text_obj);

	int prev_mouse_stat = LCGE_MOUSE_BUTTON_RELEASED;

	while (lcge_window_is_open()) {
		// Update
		int curr = lcge_get_mouse_button(LCGE_MOUSE_BUTTON_LEFT);
		if (curr == LCGE_MOUSE_BUTTON_RELEASED &&
		    prev_mouse_stat == LCGE_MOUSE_BUTTON_PRESSED) {
			clicks++;
		}
		prev_mouse_stat = curr;

		LCGE_cursor_pos pos = lcge_get_cursor_position();
		sprintf(pos_text, "Pos: %g, %g", pos.x, pos.y);
		sprintf(clicks_text, "Clicks: %d", clicks);

		lcge_text_set(pos_text_obj, pos_text, (WIDTH - width) / 2.0f,
			      (HEIGHT - height) / 2.0f + height);
		lcge_text_set(clicks_text_obj, clicks_text,
			      (WIDTH - width) / 2.0f,
			      (HEIGHT - height) / 2.0f + height + 40.0f);

		// Do any drawing here
		lcge_window_clear();
		lcge_text_draw(pos_text_obj, 255, 255, 255);
		lcge_text_draw(clicks_text_obj, 255, 255, 255);

		// Get ready for next iteration
		lcge_clock_tick(clock);
		lcge_window_update();
	}
	lcge_clock_delete(clock);
	lcge_text_delete(pos_text_obj);
	lcge_text_delete(clicks_text_obj);
	lcge_font_delete(font);

	lcge_exit();

	return 0;
}
