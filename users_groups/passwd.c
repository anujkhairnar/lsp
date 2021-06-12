#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

int main()
{
	//getpwnam - get user details by providing user name
	printf("getpwnam - get user details by providing user name\n");
	struct passwd *pass = getpwnam("anuj");
	printf("pw_name=%s\npw_passwd=%s\npw_uid=%d\npw_gid=%d\npw_gecos=%s\npw_dir=%s\npw_shell=%s\n",pass->pw_name,pass->pw_passwd,pass->pw_uid,pass->pw_gid,pass->pw_gecos,pass->pw_dir,pass->pw_shell);
	
	//getpwuid - get user details by providing user id
	printf("\ngetpwuid - get user details by providing user id\n");
	struct passwd *pass_uid = getpwuid(1000);
	printf("pw_name=%s\npw_passwd=%s\npw_uid=%d\npw_gid=%d\npw_gecos=%s\npw_dir=%s\npw_shell=%s\n",pass_uid->pw_name,pass_uid->pw_passwd,pass_uid->pw_uid,pass_uid->pw_gid,pass_uid->pw_gecos,pass_uid->pw_dir,pass_uid->pw_shell);
}
