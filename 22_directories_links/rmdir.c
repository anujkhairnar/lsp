#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage Error, %s <dir_name>", argv[0]);
	}

	int ret = rmdir(argv[1]);

	if(ret < 0)
	{
		perror("rmdir ");
		exit(EXIT_FAILURE);
	}
	return 0;
}
