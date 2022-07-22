#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>



int main(int argc, char *argv[])
{

	char *env_var[] = {"USER=root",NULL};

	execle("/bin/sh","sh",NULL,env_var);
	

	return(0);

}

