#include<stdio.h>
#include<unistd.h>
#include<string.h>




int main()
{

	char str1[] = "man";

	char str2[] = "hello";

	printf("before memcpy %s\n",str1);
	memcpy(str1,str2,sizeof(str2));

	printf("after memcpy %s\n",str1);


	return 0;
}

	


