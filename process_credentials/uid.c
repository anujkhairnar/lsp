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
	
	
	//we are setting uid here which requires sudo previledges. setuid returns 0 on success and -1 on error
	if(setuid(250) < 0)
	{
		perror("setuid ");
		exit(EXIT_FAILURE);
	}
	printf("uid after setuid is %d\n", getuid());

	//we are setting euid here which requires sudo previledges. seteuid returns 0 on success and -1 on error
	if(seteuid(250) < 0)
	{
		perror("seteuid ");
		exit(EXIT_FAILURE);
	}
	printf("euid after seteuid is %d\n", geteuid());


	//we are setting gid here. setgid returns 0 on success and -1 on error
        if(setgid(1000) < 0)
        {
                perror("setgid ");
                exit(EXIT_FAILURE);
        }
        printf("gid after setgid is %d\n", getgid());

	//we are setting egid. setegid returns 0 on success and -1 on error
        if(setegid(1000) < 0)
        {
                perror("setegid ");
                exit(EXIT_FAILURE);
        }
        printf("egid after setegid is %d\n", getegid());
	
	return 0;
}
