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


	sigemptyset(&sset);
	sigaddset(&sset,SIGUSR1);
	sigaddset(&sset,SIGTERM);


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

	sigprocmask(SIG_BLOCK,&sset,NULL);
	
	while(1)
	{
	
	}


	return 0;
}







