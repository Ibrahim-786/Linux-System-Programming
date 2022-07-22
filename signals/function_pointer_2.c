#include<stdio.h>




void func1(int sig){


	printf("######### func1 call #################\n");

	printf("value of sig is %d\n",sig);
	

}

void  function(int sig, void (*func)(int)){

	printf("############# function call #################\n");

	printf("value of sig is %d and function pointer address is %u\n",sig,func);

	

	(*func)(20);

}



int main(){




	void (*ptr)(int) = func1;

	printf("address of func1 is %u\n",func1);
	printf("address assign to ptr is %u\n",ptr);

	function(10,ptr);

	return 0;
}





