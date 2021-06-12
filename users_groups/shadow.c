#include <stdio.h>
#include <stdlib.h>
#include <shadow.h>

int main()
{
	//getspnam - get username and encrypted password by providing user name
	printf("line no. %d\n",__LINE__);
	struct spwd *passwd = getspnam("anuj");
	printf("line no. %d\n",__LINE__);
	if(passwd == NULL)
	{
		printf("line no. %d\n",__LINE__);
		perror("getspnam ");
		exit(EXIT_FAILURE);
	}
	printf("line no. %d\n",__LINE__);
	printf("sp_namp=%s\nsp_pwdp=%s\n",passwd->sp_namp,passwd->sp_pwdp);
	printf("line no. %d\n",__LINE__);

	//getspent - get username and encrypted password of the ent user on the system
	struct spwd *ent_passwd = getspent();
	if(ent_passwd == NULL)
	{
		perror("getspent ");
		exit(EXIT_FAILURE);
	}
	printf("\nsp_namp=%s\nsp_pwdp=%s",ent_passwd->sp_namp,ent_passwd->sp_pwdp);
}
