#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage Error, %s <pathname>", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	int ret = unlink(argv[1]);
	if(ret < 0 )
	{
		perror("unlink ");
		exit(EXIT_FAILURE);
	}
	return 0;
}
