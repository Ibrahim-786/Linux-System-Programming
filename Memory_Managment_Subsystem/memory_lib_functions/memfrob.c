

#define _GNU_SOURCE             
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{

	int *ptr;

	int x =10;
	ptr = &x;

	printf("before memfrob %d\n",*ptr);
        memfrob(ptr, sizeof(int));

	printf("after 1st memfrob %d\n",*ptr);

        memfrob(ptr, sizeof(int));


	printf("after 2nd  memfrob %d\n",*ptr);


	return 0;
}
