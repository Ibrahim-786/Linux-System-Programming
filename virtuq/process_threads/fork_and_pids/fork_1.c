#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>

//On  success,  the  PID of the child process is returned in the parent, and 0 is returned in
//       the child.  On failure, -1 is returned in the parent, no child process is created, and  er‐
//       rno is set appropriately.


int main(int argc, char *argv[])
{

	pid_t pid;


	pid= fork();


	if(pid >0)
	{
		sleep(1);
		printf("parent process %d\n",getpid());
		sleep(2);
	}
	else if(pid == 0)
	{
		sleep(1);
		printf("child:%d  parent%d\n",getpid(),getppid());
	}
	else if(pid == -1)
	{
		perror("fork()");
	}


	return 0;


}
