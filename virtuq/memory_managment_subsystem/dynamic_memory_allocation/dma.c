#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>





int main()
{


	int *ptr;

	ptr = (int*)malloc(10*sizeof(int));
	if(ptr == NULL)
	{
		printf("malloc () failed\n");
		exit(1);
	}

	printf("size of pointer after malloc () is %d\n",sizeof(ptr));


	free(ptr);

	ptr = (int*)calloc(10,sizeof(int));
	if(ptr == NULL)
	{
		printf("calloc() failed\n");
		exit(1);
	}

	printf("size of pointer after calloc()  is %d\n",sizeof(ptr));

	ptr = realloc(ptr,5);

	if(ptr == NULL)
	{
		printf("realloc() failed\n");
		exit(1);
	}

	printf("size of pointer after realloc()  is %d\n",sizeof(ptr));

	free(ptr);

	return 0;
}

