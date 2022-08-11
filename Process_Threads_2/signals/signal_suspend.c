#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>





static void sig_f(int n)
{
	psignal(n,"Ignoring a signal");

}



int main()
{


	sigset_t sset;


	sigfillset(&sset);
	sigdelset(&sset,SIGUSR1);
	sigdelset(&sset,SIGTERM);


	if(signal(SIGUSR1,sig_f) == SIG_ERR)
	{
		perror("signal() failed");
		exit(1);
	}

	if(signal(SIGTERM,sig_f) == SIG_ERR)
	{
		perror("signal() failed");
		exit(1);
	}

	printf("process is Suspending \n");

	sigsuspend(&sset);
	printf("..Done..\n");
	
	while(1)
	{
		pause();
	
	}


	return 0;
}







