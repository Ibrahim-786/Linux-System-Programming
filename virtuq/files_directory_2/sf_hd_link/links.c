#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 



int main(int argc, char* argv[])
{

	

	int ret;


	ret=symlink("hard_link.txt", "softlink.txt");


	if(ret != 0)
	{
		perror("soft link failed");
	}

	ret =link("hard_link.txt", "new_hard_link.txt");

	if(ret != 0)
	{
		perror("hard link failed");
	}

	

	return 0;
}