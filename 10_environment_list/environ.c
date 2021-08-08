#include <stdio.h>
#include <stdlib.h>

extern char **environ; //extern keyword is used to access a global variable which is in some other file

int main()
{
	char **ep;

	for(ep = environ; *ep != NULL; ep++)
	{
		puts(*ep);
	}

	return 0;
}
