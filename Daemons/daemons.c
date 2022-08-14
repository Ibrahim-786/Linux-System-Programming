#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main()
{

	FILE *fp =NULL;

	pid_t pid = 0;
	pid_t sid = 0;

	pid = fork();

	if(pid <0)
	{
		perror("fork () failed");
		exit(1);
	}

	if(pid > 0)
	{
		printf("parent process is [%d] and child id is [%d]\n",getpid(),pid);
		exit(0);
	}

	//unmasking is important here. A umask of 0 will make newly created directories readable, writable and descendible for everyone.
	
	umask(0);

	//use whatis setsid() to understand the purpose. it creates new session.
	sid = setsid();

	if(sid == -1)
	{
		perror("setid() failed");
		//same as fork cant be negative. well we lost the fight
		exit(1);
	}

	//moving to root
	
	int ret = chdir("/home/pasha/Desktop");

	if(ret == -1)
	{
		perror("chdir() failed");
		exit(1);
	}
	//close standard file descriptors.
	
	close(0);
	close(1);
	close(2);

	//open a log file in write mode.
	fp = fopen("Report.txt","w");

	while(1)
	{
		sleep(3);
		fprintf(fp,"I am Daemon, I am Independent..\n");
		fflush(fp);
	}

	fclose(fp);




	return 0;
}



