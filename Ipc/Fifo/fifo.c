#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>




int main()
{

	if(mkfifo("testfifo",0777) == -1)
	{
		perror("mkfifo() failed");
		exit(1);
	}

	pid_t pid;


	pid = fork();

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}

	int fd;

	if(pid > 0)
	{

		int status;
		printf("parent process [%d] and it's child [%d] \n",getpid(),pid);

		fd = open("testfifo",O_WRONLY);

		if(fd == -1)
		{
			printf("parent open\n");
			perror("open() failed");
			exit(1);
		}
		

		for(int i =0 ;i<10;i++)
			write(fd,"hello",6);

		write(fd,"end",4);

		wait(&status);

		
		exit(0);
	}
	else if (pid == 0)
	{
		printf("child process pid is [%d] and it's parent [%d]\n",getpid(),getppid());

		sleep(1);

		fd = open("testfifo",O_RDONLY);

		if(fd == -1)
		{

			printf("child open\n");
			perror("open() failed");
			exit(1);
		}
		char buf[24];
		while(1)
		{
			read(fd,buf,6);

			printf("%s\n",buf);

			if(strcmp(buf,"end") == 0)
				break;
		}


	
	}

				
	close(fd);


	return 0;
}
