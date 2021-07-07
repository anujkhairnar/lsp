#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **env;
	printf("env = %s\n", getenv("PATH"));
	if(env == NULL)
	{
		perror("getenv ");
		exit(EXIT_FAILURE);
	}
	return 0;
}

