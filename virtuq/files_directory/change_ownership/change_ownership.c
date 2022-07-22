#include <stdio.h>
#include <fcntl.h>           
#include <unistd.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>

int main(int argc, char* argv[])
{

	int ret_val;

	struct passwd *sp;
	struct group *sr;

	// sp = getpwnam("pasha");
	// sr = getgrnam("pasha");

	sp = getpwnam("root");
	sr = getgrnam("games");


	ret_val = chown("test.txt",sp->pw_uid,sr->gr_gid);



	if(ret_val == -1)
	{
		perror("chown failed");
		exit(1);
	}
	
	return 0;

}