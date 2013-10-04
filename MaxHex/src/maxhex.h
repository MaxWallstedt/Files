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

#ifndef MAXHEX_H
#define MAXHEX_H

#define OK_CONTINUE	0
#define OK_BREAK	-1
#define ERR_BREAK	1

int check_args(int argc, char *argv[]);	/* check_args.c */

int check_file_changes();		/* check_file_changes.c */

int alloc_screen_buffer();		/* screen_functions.c */
void read_file_to_buffer();		/* screen_functions.c */
void print_buffer_to_screen();		/* screen_functions.c */

int exec_command(int key);		/* exec_command.c */

void release_allocs();			/* release_allocs.c */

#endif
