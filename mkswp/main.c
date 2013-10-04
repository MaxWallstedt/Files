#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *make_swp(char *);

int main(int argc, char *argv[])
{
	int c;

	if (argc != 2) {
		printf("ERROR: Wrong usage\n\n");
		printf("Usage:\n");
		printf("\t$ %s <file>\n", argv[0]);

		return 1;
	}

	char *filename = malloc(strlen(argv[1]) + 1);

	if (!filename) {
		printf("ERROR: malloc failed\n");

		return 1;
	}

	strcpy(filename, argv[1]);
	char *tmpfilename = make_swp(filename);

	if (!tmpfilename) {
		printf("ERROR: malloc failed\n");
		free(filename);

		return 1;
	}

	FILE *file = fopen(filename, "rb");

	if (!file) {
		printf("ERROR: Could not open file \"%s\"\n", filename);
		free(filename);
		free(tmpfilename);

		return 1;
	}

	FILE *tmpfile = fopen(tmpfilename, "wb");

	if (!tmpfile) {
		printf("ERROR: Could not create file \"%s\"\n", tmpfilename);
		free(filename);
		free(tmpfilename);
		fclose(file);

		return 1;
	}

	c = fgetc(file);

	while (c != EOF) {
		fputc(c, tmpfile);
		c = fgetc(file);
	}

	free(filename);
	free(tmpfilename);
	fclose(file);
	fclose(tmpfile);

	return 0;
}

char *make_swp(char *file)
{
	char *swp = malloc(strlen(file) + 6);
	int i;

	i = strlen(file) - 1;

	while (i > 0 && file[i - 1] != '/')
		i--;

	strncpy(swp, file, i);
	swp[i] = '.';
	strcpy(&swp[i + 1], &file[i]);
	strcpy(&swp[strlen(file) + 1], ".swp");

	return swp;
}
