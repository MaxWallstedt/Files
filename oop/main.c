#include <stdio.h>

#include "stringclass.h"

int main()
{
	String *s1 = newString("hello");

	printf("String s1: %s\n", s1->get(s1));

	s1->set(s1, "world");
	printf("String s1: %s\n", s1->get(s1));

	deleteString(s1);

	return 0;
}
