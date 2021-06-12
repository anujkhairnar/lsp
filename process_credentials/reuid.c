#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	//these are simple get functions
	printf("uid is %d\n", getuid());
	printf("euid is %d\n", geteuid());
	printf("gid is %d\n", getgid());
	printf("egid is %d\n", getegid());
	
	if (setreuid(250, 250) < 0)
	{
		perror("setreuid ");
		exit(EXIT_FAILURE);
	}
	printf("\nAfter setreuid:\nuid is %d\neuid is %d\n", getuid(), geteuid());

	if(setregid(1000, 1000) < 0)
	{
		perror("setregid ");
		exit(EXIT_FAILURE);
	}
	printf("\nAfter setregid:\ngid is %d\negid is %d\n", getgid(), getegid());

	return 0;
}
