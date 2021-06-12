#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	uid_t ruid, euid, suid;
	gid_t rgid, egid, sgid;
	
	//getting ruid, euid, suid
	if(getresuid(&ruid,&euid,&suid) < 0)
	{
		perror("getresuid ");
		exit(EXIT_FAILURE);
	}
	printf("Real user id is: %d\nEffective user id is: %d\nSaved user id is: %d\n", ruid, euid, suid);

	//getting rgid, egid, sgid
	if(getresgid(&rgid,&egid,&sgid) < 0)
	{
		perror("getresgid ");
		exit(EXIT_FAILURE);
	}
	printf("\nReal group id is: %d\nEffective group id is: %d\nSaved groupd id is: %d\n", rgid, egid, sgid);

	/*
	//setting ruid, euid, suid and then getting the same (the new values)
	if(setresuid(250,250,250) < 0)
	{
		perror("setresuid ");
		exit(EXIT_FAILURE);
	}
	
	if(getresuid(&ruid,&euid,&suid) < 0)
	{
		perror("getresuid ");
		exit(EXIT_FAILURE);
	}
	printf("\nAfter setresuid\nNew real user id is: %d\nNew effective user id is: %d\nNew saved user id is: %d\n", ruid, euid, suid);
	*/

	//setting rgid, egid, sgid and then getting the same (the new values)
	if(setresgid(250,250,250) < 0)
	{
		perror("setresgid ");
		exit(EXIT_FAILURE);
	}
	
	if(getresgid(&rgid,&egid,&sgid) < 0)
	{
		perror("getresgid ");
		exit(EXIT_FAILURE);
	}
	printf("\nNew real group id is: %d\nNew effective group id is: %d\nNew saved user id is: %d\n", rgid, egid, sgid);

	return 0;
}
