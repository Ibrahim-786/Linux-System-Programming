#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <stdlib.h>





int main(int argv, char *argc[])
{

	int fd;

	fd=open("myfile.txt",O_RDONLY);

	if(fd == -1)
	{
		perror("open failed");
		exit(1);
	}

	int ret =  flock(fd, LOCK_EX);
	if(ret != 0)
	{
		perror("flock failed");
		exit(1);
	}

	sleep(3);
	close(fd);
	return 0;

}

