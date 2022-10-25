#include<stdio.h>
#include<unistd.h>




int main()
{


	printf("these is exec1\n");
	int ret = execv("./exec2",NULL);

	printf("after execv %d\n",ret);




	return 0;


}


