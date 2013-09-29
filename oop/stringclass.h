#ifndef STRINGCLASS_H
#define STRINGCLASS_H

typedef struct StringClass String;

struct StringClass {
	/* Variables */
	char *str;

	/* Functions */
	char *(*get)(String *);
	void (*set)(String *, char *);
	int (*length)(String *);
};

/* Constructor */
String *newString(char *);

/* Destructor */
void deleteString(String *);

#endif
