#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int my_system(const char* cmd)
{
	pid_t child_pid;
int status = 0;
	child_pid = fork();

	switch(child_pid)
	{
		case -1:
			perror("fork");
			return -1;
		case 0:
			execl("/bin/bash","bash","-c",cmd,NULL);
			perror("execl");
			_exit(-127);
		default:
			wait(&status);
			break;
	}
	printf("cmd return value is %d\n", status >> 8);
	return 0;
}

int main()
{
	int ret = my_system("ls -l");
}
