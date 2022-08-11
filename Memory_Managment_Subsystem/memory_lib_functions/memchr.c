#include<stdio.h>
#include<string.h>


int main()
{


	char *str1= "hello";


	if(memchr(str1,'e',5) == NULL)
	{
		printf("character 'e' is not found in str1\n");
	}
	else
		
		printf("character 'e' is found in str1\n");
	

	if(memchr(str1,'I',5) == NULL)
	{
		printf("character 'I' is not found in str1\n");
	}
	else
		
		printf("character 'I' is found in str1\n");
	return 0;

}

