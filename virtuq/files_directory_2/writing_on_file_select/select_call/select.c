#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#



#define BUFSIZE 80


int main(int argv, char *argc[])
{

	int retval;
	fd_set rfds;
	char buf[BUFSIZE];

	struct timeval ts;
        ts.tv_usec = 0;

	while(1)
	{
	
		
		FD_ZERO(&rfds);
		FD_SET(STDIN_FILENO,&rfds);
		
		ts.tv_sec = 2;
		retval = select(STDIN_FILENO+1,&rfds,NULL,NULL,&ts);

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

		printf("[%d]:Buf: %s",(int)ts.tv_sec,buf);
	}


	return 0;

}

