#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>





static void sig_f(int n)
{
	psignal(n,"Ignoring a signal");

	if(n==15) //raise signal to ower self
	{
		raise(SIGUSR1);
	}
}



int main()
{


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

	while(1)
	{
	
	}


	return 0;
}







