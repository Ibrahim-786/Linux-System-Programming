#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#include <signal.h>
#include <poll.h>


#define BUFSIZE 80


int main(int argv, char *argc[])
{

	int retval;
	struct pollfd fds[1];
	char buf[BUFSIZE];

//	struct timeval ts;
   

	while(1)
	{
	
		
		fds[0].fd = STDIN_FILENO;
		fds[0].events = POLLIN;
	

		retval = poll(fds,1,1000);

		if(retval == -1)
		{
			perror("select failed");
			return(1);
		}
		else if(retval == 0)
		{
			printf("time out\n");
			perror("select()");
			return(1);
		}

		read(STDIN_FILENO,buf,BUFSIZE);

		printf("Buf: %s",buf);
	}


	return 0;

}

