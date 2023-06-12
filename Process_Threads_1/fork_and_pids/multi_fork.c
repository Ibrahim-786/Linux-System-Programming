#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("started from main. calling fork\n");

	fork(); //fork 1

	printf("Fork 1 was called\n");

	fork(); //fork 2

	printf("Fork 2 was called\n");

	fork();  //fork 3 
		 

	printf("Fork 3 was called\n");

	fork();  //fork 4	
	printf("Fork 4 was called\n");


	while(1);

	return 0;

}
