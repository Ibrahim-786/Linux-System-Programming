#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



int main()
{


	pid_t pid;

	pid = fork();

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}

	int status;
	if(pid != 0)
	{
	
	
		int pid_child =  wait(&status);
		if(pid_child == -1)
		{
			perror("wait() failed");
			exit(1);
		}
		printf("parent process \n parent pid [%d] and child pid [%d]\n",getpid(),pid_child);
		if(WIFEXITED(status))
		{
			printf("child exited normally\n");
		}
	}


	if(pid == 0)
	{
		printf("parent [%d] child [%d]\n",getppid(),getpid());
		sleep(1);
	}
	return 0;
}

