#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage Error, %s <dir_name>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int ret = mkdir(argv[1], 0777);

	if(ret < 0)
	{
		perror("mkdir ");
		exit(EXIT_FAILURE);
	}
	return 0;
}
