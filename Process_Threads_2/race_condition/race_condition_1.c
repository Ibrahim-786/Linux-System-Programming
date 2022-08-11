#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>



//two process or thread trying to modify same data struct at same time, resulting in producing underministic behaviour


int main()
{



	int pid;

	pid = fork();


	if(pid == -1)
	{
		perror("fork() failed\n");
		exit(1);
	}

	if(pid > 0)
	{
		printf("parent process %d\n",getpid());
		for(int i=0; i<10;i++)
		{
			printf("parent process\n");
			sleep(0.5);
		}
	}

	if(pid == 0)
	{
		printf("child process\n");

		for(int i=0; i<10;i++)
		{
			printf("child process\n");
			sleep(0.5);
		}
	}


	return 0;
}
