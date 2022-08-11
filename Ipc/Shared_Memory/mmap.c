#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/mman.h>


//to see anonymous mem allocation when process is sleeping
//pmap -x pid 


int main()
{



	char* ptr = mmap(NULL, 1024*sizeof(char), (PROT_READ|PROT_WRITE), (MAP_ANONYMOUS|MAP_SHARED), -1, 0);


	pid_t pid;

	pid = fork();

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}

	if(pid >0)
	{
		printf("parent process pid id [%d] and it's child [%d]\n",getpid(),pid);

		for(int i=0;i<10;i++)
			*(ptr+i) = i+10;

		int status;

		wait(&status);
		sleep(100);
	}
	else if(pid == 0)
	{
		printf("child process pid is [%d] and it's parent is [%d]\n",getpid(),getppid());
		sleep(1);

		for(int i=0;i<10;i++)
			printf("%d\n",(int)(*(ptr+i)));
		sleep(100);
	}

	munmap(ptr,1024*sizeof(char));


	return 0;


}

