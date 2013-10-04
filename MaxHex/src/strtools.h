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

#ifndef STRTOOLS_H
#define STRTOOLS_H

char *to_lower(char *str);		/* to_lower.c */
int streq(char *str1, char *str2);	/* streq.asm */
int strlenM(char *str);			/* strlenM.asm */

#endif
