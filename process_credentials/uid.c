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

	//we are setting uid here which requiers sudo previledges. setuid returns 0 on success and -1 on error
	if(setuid(250) < 0)
	{
		perror("setuid ");
		exit(EXIT_FAILURE);
	}
	printf("uid after setuid is %d\n", getuid());
	return 0;	
}
