

#define _GNU_SOURCE             
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>

int main()
{

	int *ptr;

	ptr = malloc(10*sizeof(int));


        if(mlock(ptr, 10*sizeof(int)) !=0)
	{
		perror("mlcok() failed");
	}


	free(ptr);



	return 0;
}
