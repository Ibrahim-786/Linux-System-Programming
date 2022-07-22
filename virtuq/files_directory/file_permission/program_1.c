#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* look for man 2 chmod and access for more information */

int main(int argc, char* argv[])
{

	int id;
	id = chmod("test.sh",S_IRUSR |S_IWUSR);

	if(id==-1)
	{
		perror("chmod failed");
		exit(1);
	}

	int check;
	/* R_OK, W_OK, and X_OK.  F_OK tests for the existence of the file. */
	check= access("test.sh",X_OK);
	//check= access("test.sh",R_OK);
	//check= access("test.sh",W_OK);



	if(check == -1)
	{
		perror("access failed");
	}


	return 0;

}