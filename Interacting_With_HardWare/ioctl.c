#include<stdio.h>
#include<unistd.h>
#include <sys/ioctl.h>
#include<fcntl.h>
#include<termios.h>

#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main()
{

	int fd, serial;
	umask(0);
	
	fd = open("/dev/ttyS0",O_RDONLY);

	if(fd == -1)
	{
		perror("open() failed");
		exit(1);
	}

	ioctl(fd,TIOCMGET,&serial);

	if(serial & TIOCM_DTR)
	{
		printf("TIOCM_DTR is  not set\n");
	}
	else
	{

		printf("TIOCM_DTR is set\n");
	}

	return 0;
}
