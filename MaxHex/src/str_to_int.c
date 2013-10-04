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

#include "strtools.h"

int is_hex(char *str)
{
	if (str[0] == '0' && str[1] == 'x')
		str += 2;
	else if (str[strlenM(str) - 1] == 'h')
		str[strlenM(str) - 1] = '\0';
	else
		return 0;

	while (*str) {
		if (*str < '0'
		    || (*str > '9' && *str < 'a')
		    || *str > 'f')
			return 0;

		++str;
	}

	return 1;
}

int is_oct(char *str)
{
	if (str[0] == '0' && str[1] == 'o')
		str += 2;
	else if (str[strlenM(str) - 1] == 'o')
		str[strlenM(str) - 1] = '\0';
	else if (str[0] != '0')
		return 0;

	while (*str) {
		if (*str < '0' || *str > '7')
			return 0;

		++str;
	}

	return 1;
}

int is_bin(char *str)
{
	if (str[0] == '0' && str[1] == 'b')
		str += 2;
	else if (str[strlenM(str) - 1] == 'b')
		str[strlenM(str) - 1] = '\0';
	else
		return 0;

	while (*str) {
		if (*str < '0' || *str > '1')
			return 0;

		++str;
	}

	return 1;
}

int is_dec(char *str)
{
	if (str[0] == '0' && str[1] == 'd')
		str += 2;
	else if (str[strlenM(str) - 1] == 'd')
		str[strlenM(str) - 1] = '\0';

	while (*str) {
		if (*str < '0' || *str > '9')
			return 0;

		++str;
	}

	return 1;
}

unsigned long long str_to_hex(char *str)
{
	unsigned long long build = 0;

	if (str[0] == '0' && str[1] == 'x')
		str += 2;
	else if (str[strlenM(str) - 1] == 'h')
		str[strlenM(str) - 1] = '\0';

	while (*str) {
		if (*str >= '0' && *str <= '9')
			build = build * 0x10 + *str - '0';
		else
			build = build * 0x10 + *str - 'a' + 0x0A;

		++str;
	}

	return build;
}

unsigned long long str_to_oct(char *str)
{
	unsigned long long build = 0;

	if (str[0] == '0' && str[1] == 'o')
		str += 2;
	else if (str[strlenM(str) - 1] == 'o')
		str[strlenM(str) - 1] = '\0';

	while (*str) {
		build = build * 010 + *str - '0';
		++str;
	}

	return build;
}

unsigned long long str_to_bin(char *str)
{
	unsigned long long build = 0;

	if (str[0] == '0' && str[1] == 'b')
		str += 2;
	else if (str[strlenM(str) - 1] == 'b')
		str[strlenM(str) - 1] = '\0';

	while (*str) {
		build = (build << 1) + *str - '0';
		++str;
	}

	return build;
}
unsigned long long str_to_dec(char *str)
{
	unsigned long long build = 0;

	if (str[0] == '0' && str[1] == 'd')
		str += 2;
	else if (str[strlenM(str) - 1] == 'd')
		str[strlenM(str) - 1] = '\0';

	while (*str) {
		build = build * 10 + *str - '0';
		++str;
	}

	return build;
}
