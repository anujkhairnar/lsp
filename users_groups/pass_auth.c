#define _DEFAULT_SOURCE /*Get getpass() declaration from <unistd.h>*/
#define _XOPEN_SOURCE /*Get crypt() declaration from <unistd.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <shadow.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <error.h>

int main(int argc,char**argv)
{
	char *username,*password,*encrypted,*p;
	struct passwd *pwd; //etc/passwd
	struct spwd *spwd; //etc/shadow
	bool authOk;
	size_t len;
	long lnmax;

	printf("line no. %d\n",__LINE__);
	lnmax = sysconf(_SC_LOGIN_NAME_MAX);
	if(lnmax == -1) /*if limit is indeterminate*/
	{
		lnmax = 256; /*make a guess*/
	}
	printf("line no. %d\n",__LINE__);

	username = (char*)malloc(lnmax);
	if(username == NULL)
	{
		printf("line no. %d\n",__LINE__);
		perror("malloc ");
		exit(EXIT_FAILURE);
	}
	printf("line no. %d\n",__LINE__);

	printf("Username: ");
	printf("line no. %d\n",__LINE__);
	fflush(stdout);
	printf("line no. %d\n",__LINE__);
	if(fgets(username,lnmax,stdin) == NULL)
	{
		free(username);
		exit(EXIT_FAILURE);	
	}
	printf("line no. %d\n",__LINE__);

	len = strlen(username);
	if(username[len -1] == '\n')
		username[len - 1] = '\0'; /*Remove trailing '\n'*/

	pwd = getpwnam(username);
	if(pwd == NULL)
		perror("getpwnam");
	spwd = getspnam(username);
	if(spwd != NULL && errno == EACCES)
		perror("getspnam");
	if(spwd != NULL) /*If there is a shadow password record*/
		pwd->pw_passwd = spwd->sp_pwdp; /*Use the shadow password*/

	password = getpass("Password: ");

	/*Encrypt password and erase cleartext version immediately*/

	encrypted = crypt(password,pwd->pw_passwd);
	for(p = password; *p != '\0';)
		*p++ = '\0';
	
	if(encrypted == NULL)
		perror("crypt");

	authOk = strcmp(encrypted,pwd->pw_passwd) == 0;
	if(!authOk)
	{
		printf("Incorrect password\n");
		free(username);
		exit(EXIT_FAILURE);
	}
	printf("Successfully authenticated: UID=%ld\n",(long)pwd->pw_uid);

	free(username);
	exit(EXIT_SUCCESS);
}
