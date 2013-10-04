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

#ifndef STR_TO_INT_H
#define STR_TO_INT_H

extern int is_hex(char *str);
extern int is_oct(char *str);
extern int is_bin(char *str);
extern int is_dec(char *str);
extern unsigned long long str_to_hex(char *str);
extern unsigned long long str_to_oct(char *str);
extern unsigned long long str_to_bin(char *str);
extern unsigned long long str_to_dec(char *str);

#endif
