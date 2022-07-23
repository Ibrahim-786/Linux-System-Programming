#include <stdio.h>
#include <setjmp.h>

jmp_buf main_buf, child_buf;


void child()
{

	if(!setjmp(child_buf))
	{
		printf("child \n");
		longjmp(main_buf,1);
	}

	printf("child return\n");
}


int main()
{


	if(!setjmp(main_buf))
	{
		printf("child first call\n");
		child();
	}

	if(!setjmp(main_buf))
	{
		printf("child last call\n");
		longjmp(child_buf,1);
	}

	printf("main return\n");


	return 0;
}

//output
// child first call
// child 
// child last call
// child return
// main return
