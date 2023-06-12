#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <sys/wait.h>

//what is dead lock
//dead lock is situation each of the process waiting other process to complete, and hence they are not able to make progress

//what is Race condition
//when two threads access a shared variable at the same time, ended up with unexpected behaviour


int main(int argc, char *argv[] )
{

 	int fd,pid;

 	fd=open("myfile.txt",O_RDWR);

	if(fd == -1)
	{
		perror("open failed");
		exit(1);
	}

	pid = fork();

	if(pid >0)
	{
		printf("parent requesting lock\n");

		int ret_1 =  flock(fd, LOCK_EX);
		if(ret_1 != 0)
		{
			perror("flock failed");
			exit(1);
		}

		printf("parent acquired lock\n");

		
		int child_process_id = wait(NULL);
		printf("parent pid is %d and child pid is %d\n",getpid(),child_process_id);

		int ret = write(fd,"ibrahim",8);
		if(ret == -1)
		{
			perror("write () failed");
			exit(1);
		}
		printf("number of bytes write %d\n",ret);
		sleep(1);
		
		ret_1 =  flock(fd, LOCK_UN);
                if(ret_1 != 0)
                {
                        perror("flock failed");
                        exit(1);
                }

		printf("parent releasing a lock \n");
	}



	if(pid == 0)
	{
	
		printf("child requesting lock");

		sleep(4);
		int ret_2 =  flock(fd, LOCK_EX);
                if(ret_2 != 0)
                {
                        perror("flock failed");
                        exit(1);
                }

		
                printf("child acquired lock\n");
		
		printf("parent pid is %d child pid is %d\n",getppid(),getpid());
                
                int ret_3 = write(fd,"pasha",6);
                if(ret_3 == -1)
                {
                        perror("write () failed");
                        exit(1);
                }
                printf("number of bytes write %d\n",ret_3);

                ret_3 =  flock(fd, LOCK_UN);
                if(ret_3 != 0)
                {
                        perror("flock failed");
                        exit(1);
                   
		}

		printf("child is  releasing a lock \n");
	
	
	}

	if(pid == -1)
	{
		perror("fork() failed");
		exit(1);
	}


	return 0;

}
