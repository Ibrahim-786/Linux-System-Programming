#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define MAXLINE 16


int main(int argc, char *argv[])
{

	int n;
	int fd[2];
	pid_t pid;
	char line[MAXLINE];


	if(pipe(fd) == -1)
	{
		perror("pipe () failed");
		exit(1);
	}
	
	if((pid = fork()) == -1)
	{
		perror("fork() failed");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("child process [%d] [%d]\n",getpid(),getppid());
		close(fd[1]);
		n = read(fd[0],line,MAXLINE);
		write(STDOUT_FILENO,line,n);
	}

	else
	{
	
		printf("parent process [%d]  [%d]\n",getpid(),pid);
		close(fd[0]);
		write(fd[1],"hello world\n",12);
		sleep(2);
	}



	return 0;

}
