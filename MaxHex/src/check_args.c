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

#include <stdio.h>
#include <stdlib.h>

#include "maxhex.h"
#include "globl.h"
#include "strtools.h"
#include "str_to_int.h"
#include "help_version.h"

int check_args(int argc, char *argv[])
{
	int i;
	char *arg_lower = NULL;

	char *long_help = "--help";
	char *short_help = "-h";

	char *long_version = "--version";
	char *short_version = "-v";

	char *long_address = "--address";
	char *short_address = "-a";

	for (i = 1; i < argc; ++i) {
		arg_lower = to_lower(argv[i]);

		if (!arg_lower) {
			fputs("ERROR: malloc failed\n", stderr);
			goto quit_err_break;
		}

		if (streq(arg_lower, long_help)
		    || streq(arg_lower, long_help + 1)
		    || streq(arg_lower, short_help)) {
			print_help(argv[0], strlenM(argv[0]));
			goto quit_ok_break;
		} else if (streq(arg_lower, long_version)
		           || streq(arg_lower, long_version + 1)
		           || streq(arg_lower, short_version)) {
			print_version();
			goto quit_ok_break;
		} else if (streq(arg_lower, long_address)
		           || streq(arg_lower, long_address + 1)
		           || streq(arg_lower, short_address)) {
			++i;

			if (i == argc) {
				fprintf(stderr,
			"ERROR: Must specify address after \"%s\"\n",
				        argv[i - 1]);
				goto quit_err_break;
			}

			free(arg_lower);
			arg_lower = to_lower(argv[i]);

			if (!arg_lower) {
				fputs("ERROR: malloc failed\n", stderr);
				goto quit_err_break;
			}

			if (is_hex(arg_lower)) {
				cur_addr = str_to_hex(arg_lower);
			} else if (is_oct(arg_lower)) {
				cur_addr = str_to_oct(arg_lower);
			} else if (is_bin(arg_lower)) {
				cur_addr = str_to_bin(arg_lower);
			} else if (is_dec(arg_lower)) {
				cur_addr = str_to_dec(arg_lower);
			} else {
				fprintf(stderr,
			"ERROR: Invalid address format %s\n",
				        argv[i]);
				goto quit_err_break;
			}
		} else if (filename) {
			fputs(
		"ERROR: Can only edit one file at the time\n",
			      stderr);
			goto quit_err_break;
		} else {
			filename = argv[i];
		}

		free(arg_lower);
		arg_lower = NULL;
	}

	if (!filename) {
		fputs("ERROR: Must specify file to open\n", stderr);
		goto quit_err_break;
	}

	if (!(file = fopen(filename, "rb"))) {
		fprintf(stderr,
		        "ERROR: Can't open file \"%s\"\n", filename);
		goto quit_err_break;
	}

	for (end_addr = -1; fgetc(file) != EOF; ++end_addr)
		;

	if (end_addr == -1) {
		fprintf(stderr, "ERROR: File \"%s\" is empty\n", filename);
		fclose(file);
		goto quit_err_break;
	}

	if (cur_addr > end_addr) {
		fprintf(stderr,
	"ERROR: File \"%s\" does not contain address 0x%016llX\n",
		        filename, cur_addr);
		fclose(file);
		goto quit_err_break;
	}

	fclose(file);

	return OK_CONTINUE;

quit_ok_break:
	free(arg_lower);

	return OK_BREAK;

quit_err_break:
	if (arg_lower)
		free(arg_lower);

	return ERR_BREAK;
}
