#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	char buffer[1024] = {0};
	if(argc != 2)
	{
		printf("Usage Error, %s <pathname>", argv[0]);
		exit(EXIT_FAILURE);
	}
	int ret = readlink(argv[1], buffer, 1024);
	if(ret < 0)
	{
		perror("readlink ");
		exit(EXIT_FAILURE);
	}
	printf("Pointing to: %s\n", buffer);
	return 0;
}
