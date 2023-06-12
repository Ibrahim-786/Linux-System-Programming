#include<stdio.h>
#include<unistd.h>


int main()
{

	int i;

	for(i=0; i<3;  i++)
	{
		if(fork()==0)
		{
			printf("Loop %d- PID %d\tPPID.%d\n",i,getpid(),getppid());
		}
	}


	while(1);

	return 0;
}
