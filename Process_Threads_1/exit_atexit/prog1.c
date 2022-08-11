#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>





void call_on_exit(void)
{

	printf("called at exit\n");
}



int main()
{


	pid_t pid;


	// registering a call to execute when exit is called
	atexit(call_on_exit);

	pid = fork();

	//here parent exit before child, so control is given to init process

	if(pid>0)
	{
		sleep(1);
		printf("self process %d\n",getpid());
		exit(0);
	}
	else if(pid == 0)
	{
		sleep(1);
		printf("child %d and parent %d\n",getpid(),getppid());
		//child is not exiting 
		//exit(0);
		return 0;
		
	}
	else
	{
		perror("fork() failed");
		exit(1);
	}

	return 0;
}