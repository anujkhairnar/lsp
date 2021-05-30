#include <stdio.h>
#include <stdlib.h>
#include <grp.h>

int main()
{
	//getgrnam - get user details by providing group name
	printf("getgrnam - get user details by providing group name\n");
	struct group *grp = getgrnam("lxd");
	perror("getgrnam ");
	printf("gr_name=%s\ngr_passwd=%s\ngr_gid=%d\ngr_mem=%s\n",grp->gr_name,grp->gr_passwd,grp->gr_gid,grp->gr_mem[0]);
	
	//getgrgid - get user details by providing group id
	printf("\ngetgrgid - get user details by providing group id\n");
	struct group *grp_gid = getgrgid(131);
	printf("gr_name=%s\ngr_passwd=%s\ngr_gid=%d\ngr_mem=%s\n",grp_gid->gr_name,grp_gid->gr_passwd,grp_gid->gr_gid,grp_gid->gr_mem[0]);
}
