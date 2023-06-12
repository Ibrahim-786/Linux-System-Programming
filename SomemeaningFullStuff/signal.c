#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig_num)
{
	char *s=strsignal(sig_num);
	printf("%d -->%s\n",sig_num,s);
}
void main()
{
	int pid,p_pid;
	printf("%d %d\n",getppid(),pid);

	//child
	pid=fork();
	if(pid==0)
	{
		printf("child created\n");
		sleep(10);//parent to execute
		printf("sending signal to parent\n");
		for(int i=0;i<7;i++)
		{
			kill(getppid(),SIGINT);
			kill(getppid(),SIGUSR1);
			sleep(2);
		}
	}
	else
	{
		printf("hi from parent\n");
		signal(SIGINT,sig_handler);
		signal(SIGUSR1,sig_handler);
		while(1)
			sleep(2);
	}
}

