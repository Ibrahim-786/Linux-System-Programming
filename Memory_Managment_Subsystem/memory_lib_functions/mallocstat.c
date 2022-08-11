

#define _GNU_SOURCE             
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <malloc.h>



int main()
{

	int *ptr;

	ptr = malloc(10*sizeof(int));

	printf("malloc_usable_size %d\n\n",malloc_usable_size(ptr));



	malloc_stats();
	

	free(ptr);



	return 0;
}
