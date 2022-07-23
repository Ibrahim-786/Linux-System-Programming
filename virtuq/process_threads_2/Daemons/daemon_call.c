#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>




int main()
{

	pid_t pid;

	pid = fork();


	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}

	if(pid >0)
	{
		daemon(1,1);

		sleep(5);
		printf("parent [%d]\n",getpid());
	}
	if(pid == 0)
	{
		sleep(2);
		printf("child [%d]\n",getpid());
		sleep(2);
	}

	return 0;
}

