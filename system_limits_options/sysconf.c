#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	printf("ARG_MAX = %ld\n", sysconf(_SC_ARG_MAX));
	printf("CLK_TCK = %ld\n", sysconf(_SC_CLK_TCK));
	printf("LOGIN_NAME_MAX = %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
	printf("OPEN_NAME = %ld\n", sysconf(_SC_OPEN_MAX));
	printf("NGROUPS_MAX = %ld\n", sysconf(_SC_NGROUPS_MAX));
	printf("PAGESIZE = %ld\n", sysconf(_SC_PAGESIZE));
	printf("RTSIG_MAX = %ld\n", sysconf(_SC_RTSIG_MAX));
	printf("SIGQUEUE = %ld\n", sysconf(_SC_SIGQUEUE_MAX));
	printf("STREAM_MAX = %ld\n", sysconf(_SC_STREAM_MAX));
	printf("NAME_MAX = %ld\n", sysconf(_PC_NAME_MAX));
	printf("PATH_MAX = %ld\n", sysconf(_PC_PATH_MAX));
	printf("PIPE_BUF = %ld\n", sysconf(_PC_PIPE_BUF));

}
