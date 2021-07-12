#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage Error, %s <path>", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	char buffer[PATH_MAX] = {};
	char* ret = realpath(argv[1], buffer);

	if(ret == NULL)
	{
		perror("realpath ");
		free(ret);
		exit(EXIT_FAILURE);
	}
	printf("Realpath = %s\n", ret);
	printf("Address of ret (in hex format)= %p\n", ret);
	printf("Address of buffer (in default hex format)= %p\n", buffer);
	
	printf("Address of ret in integer format = %ld\n", (unsigned long int)ret);
	printf("Address of buffer in integer format = %ld\n", (unsigned long int)buffer);
	return 0;
}
