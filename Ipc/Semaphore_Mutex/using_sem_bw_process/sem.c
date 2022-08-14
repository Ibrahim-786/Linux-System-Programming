#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/mman.h>





int main()
{



	void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
	int *ptr = mmap(NULL,1024*sizeof(char),PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1,0);

	//Locate semaphore at the end these area 
	

	sem_t *sem_var;

	sem_var = (sem_t*)(ptr+1024*sizeof(char)-sizeof(sem_var));
	
	// 1- means using between process not thread
	// 0- means only one process access like child 
	if(sem_init(sem_var,1,0))  //ensure child blocks
	{
		perror("sem_init() failed");
		exit(1);
	}

	pid_t pid = fork();

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}
	if(pid > 0)
	{
		printf("parent process [%d] and it's child is [%d]\n",getpid(),pid);

		//these sleep will make child process to wait on sem_wait
		sleep(5);
		for(int i=0; i<10; i++)
			*(ptr+i) = i+10;

		sem_post(sem_var);

		int status;
		
		//wait for child
		wait(&status);

		exit(0);
	}
	if(pid == 0)
	{
		printf("child process and pid is [%d] and parent is [%d]\n",getpid(),getppid());

		printf("child is waiting for parent to write\n");

		sem_wait(sem_var);

		printf("child got the access to shared and will try to read now\n");

		for(int i=0;i<10;i++)
			printf("%d ",*(ptr+i));
		printf("\n");

	        sem_post(sem_var);
		printf("child done with reading releasing lock\n");
	}


	return 0;
}





