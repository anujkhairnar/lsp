#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	int fd = 3;
	char buf[10];
	int ret = read(fd,buf,10);
	if(ret < 0)
	{
		perror("read ");
		printf("read : %s\n",strerror(errno));
		exit(EXIT_FAILURE);
	}
}
