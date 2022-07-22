#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


#define BUFSIZE 80


int main(int argv, char *argc[])
{

	int retval,fd;
	//char buf[BUFSIZE];
	
		fd = open("myfile.txt",O_RDONLY);

		if(fd == -1)
		{
			perror("open()");
			return(1);
		}

		retval  = fcntl(fd,F_GETFD);

		if(retval == -1)
		{
			perror("fcntl failed");
		}
		printf("flags :%d\n",retval);

		retval  = fcntl(fd,F_GETOWN);
		
		if(retval == -1)
                {
                        perror("fcntl failed");
                }
                printf("flags :%d\n",retval);

		close(fd);

	return 0;

}

