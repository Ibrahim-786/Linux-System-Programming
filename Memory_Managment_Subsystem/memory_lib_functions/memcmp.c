#include<stdio.h>
#include<string.h>


int main()
{


	char *str1= "hello";

	char *str2= "hello";
	char *str3= "hell";


	if(memcmp(str1,str2,sizeof(str1)) != 0)
	{
		printf("str1 and str2 are not same\n");
	}
	else
		printf("str1 and str2 are same\n");

	
	if(memcmp(str1,str3,sizeof(str1)) != 0)
	{
		printf("str1 and str3 are not same\n");
	}
	else
	
		printf("str1 and str3 are same\n");
	
	return 0;

}

