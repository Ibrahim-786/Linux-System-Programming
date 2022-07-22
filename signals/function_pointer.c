#include<stdio.h>



int function(int x,int y){


	return x+y;
}


int main(){


	int x =0;

	int (*ptr) (int,int);

	ptr=function;

	printf("addition of two number is %d",(*ptr)(10,12));


	return 0;
}

