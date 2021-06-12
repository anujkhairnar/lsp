#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main()
{
	struct utsname ut_buf;

	//int ret = uname(&ut_buf);

	if(uname(&ut_buf) < 0)
	{
		perror("uname ");
		exit(EXIT_FAILURE);
	}
	
	printf("sysname : %s\n", ut_buf.sysname);
	printf("nodename : %s\n", ut_buf.nodename);
	printf("release : %s\n", ut_buf.release);
	printf("version : %s\n", ut_buf.version);
	printf("machine : %s\n", ut_buf.machine);
	printf("domainname : %s\n", ut_buf.domainname);
	
	return 0;
}
