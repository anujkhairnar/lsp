#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("Usage error, %s <pid>", argv[0]);
		exit(EXIT_FAILURE);
	}

	kill(atoi(argv[1]), SIGINT);

	return 0;
}
