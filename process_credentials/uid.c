#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("uid is %d\n", getuid());
	printf("euid is %d\n", geteuid());
	printf("gid is %d\n", getgid());
	printf("egid is %d\n", getegid());
	return 0;	
}
