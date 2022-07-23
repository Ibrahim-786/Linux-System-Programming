#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>




int main()
{


	int pid;

	pid =fork();

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}

	if(pid > 0)
	{
		printf("parent process [%d]\n",getpid());
		pause();

		sleep(2);
	}

	if(pid == 0)
	{
		sleep(2);
		printf("child process [%d ] and parent [%d]",getpid(),getppid());
		sleep(2);
	}

	return 0;
}

