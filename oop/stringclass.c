#include <stdlib.h>
#include <string.h>

#include "stringclass.h"

char *getString(String *);
void setString(String *, char *);
int lengthString(String *);

String *newString(char *str)
{
	String *self = (String *)malloc(sizeof(String));

	self->get = &getString;
	self->set = &setString;
	self->length = &lengthString;

	self->str = NULL;
	self->set(self, str);

	return self;
}

void deleteString(String *self)
{
	if (self->str)
		free(self->str);

	free(self);
}

char *getString(String *self)
{
	return self->str;
}

void setString(String *self, char *newStr)
{
	if (self->str)
		free(self->str);

	if (newStr) {
		self->str = malloc(strlen(newStr) + 1);
		strcpy(self->str, newStr);
	}
}

int lengthString(String *self)
{
	return strlen(self->str);
}
