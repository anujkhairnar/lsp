#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	if(argc != 3)
	{
		printf("Usage Error, %s <target> <linkpath>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int ret = symlink(argv[1], argv[2]);
	if(ret < 0)
	{
		perror("symlink ");
		exit(EXIT_FAILURE);
	}
	return 0;
}
