#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>




int main()
{


	printf("process id is %d\n",getpid());
        pid_t id =  fork();
	printf("pid of child is %d\n",id);
	printf("hello world\n");





	return 0;


}

