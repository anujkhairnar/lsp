#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* shell_val = getenv("PATH");
	printf("env = %s\n", shell_val);
	return 0;
}
