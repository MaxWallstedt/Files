/* Copyright (C) 2013 Max Wällstedt
 * This file is part of MaxHex.
 *
 * MaxHex is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MaxHex is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MaxHex.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <curses.h>

#include "maxhex.h"

/* Debugging */
#include "globl.h"
/* Debugging */

int main(int argc, char *argv[])
{
	int ret = check_args(argc, argv);
	int key;

	if (ret == OK_BREAK)
		return 0;
	else if (ret == ERR_BREAK)
		return 1;

	/* Curses initialisers */
	initscr();
	raw();
	noecho();
	keypad(stdscr, TRUE);
	meta(stdscr, TRUE);
	curs_set(0);

	while (!ret) {
		if (check_file_changes())
			return 1;

		if (alloc_screen_buffer())
			return 1;

		read_file_to_buffer();
		print_buffer_to_screen();

		key = getch();
		ret = exec_command(key);
	}

	release_allocs();
	endwin();

	/* Debugging */
	printf("cur_addr:\n");
	printf("\thex: %llX\n", cur_addr);
	printf("\toct: %llo\n", cur_addr);
	printf("\tdec: %lld\n", cur_addr);
	printf("\nfilename: %s\n", filename);
	/* Debugging */

	return 0;
}
