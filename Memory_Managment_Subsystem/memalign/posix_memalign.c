#define _XOPEN_SOURCE 600


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>




int main()
{

	int *ptr;

	//memory alignment is word size 4 bytes or 2 bytes 
	ptr = malloc(10*sizeof(int));



	long sz = sysconf(_SC_PAGESIZE);
	printf("page sz is %d\n",sz);

	printf("page size is %d\n",getpagesize());
	printf("address from malloc %p\n",malloc);


	free(ptr);

	ptr = NULL;

	//memory alignment is 128 bytes
	if(posix_memalign((void**)&ptr,128,1024) == -1)
	{
		perror("posix_memalign() failed");
		exit(1);
	}
	

	sz = sysconf(_SC_PAGESIZE);
	printf("page sz is %d\n",sz);

	printf("page size is %d\n",getpagesize());
	printf("address from posix_memalign %p\n",ptr);

	free(ptr);

	return 0;
}
