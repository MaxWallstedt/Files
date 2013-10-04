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

#ifndef GLOBL_H
#define GLOBL_H

#include <stdio.h>

extern unsigned long long cur_addr;
extern unsigned long long start_addr;
extern unsigned long long end_addr;

extern char *filename;
extern FILE *file;

extern char *screen_buf;

#endif
