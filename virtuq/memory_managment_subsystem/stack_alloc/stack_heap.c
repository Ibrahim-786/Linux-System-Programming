#include<stdio.h>
#include<stdlib.h>



int main()
{


	int *ptr,*ptr1;

	ptr = alloca(10*sizeof(int));

	printf("stack address %p\n",ptr);

	ptr1= (int*)malloc(10*sizeof(int));
	
	printf("heap address %p\n",ptr1);

	printf("diff bw stack and heap is %p\n",ptr-ptr1);

	free(ptr1);

	return 0;

}



