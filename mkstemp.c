#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int fd;
	char template[] = "/tmp/anujXXXXXX";
	fd = mkstemp(template);
	if(fd < 0)
	{
		perror("mkstemp");
		exit(EXIT_FAILURE);
	}
	printf("Filename is = %s\n", template);
	while(1)
	{
	
	}
	unlink(template);
	close(fd);
	exit(EXIT_FAILURE);
}
