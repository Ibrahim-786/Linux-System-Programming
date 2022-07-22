#include<stdio.h>
#include<unistd.h>



int main(int argc, char * argv[])
{

	printf("pid of process is [%d]\n",getpid());
	sleep(15);



	return (0);
}
