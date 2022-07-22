#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>



//./zoombie_process &
//ps -o 'state uid user cmd'

//process states
//running
//waiting
//sleeping
//stopped
//zoombies


int main(int argc, char *argv[])
{

	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork()");
	}

	if(pid != 0)
	{
		printf("will create zoombie process\n");
		sleep(100);
		return(1);
	}
	int i;

	if(pid == 0)
	{
			printf("Child [%d]\n",getpid());
		for(i =0;i<INT_MAX;i++);
	}


	return(0);


}

