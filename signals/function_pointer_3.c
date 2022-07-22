#include<stdio.h>


int x=10;

void* sig_func(int sig){

	printf("############# sig_func function ###########\n");

	printf("value of sig is %d\n",sig);

	return (void*)&x;
}


void func(int sig){


	printf("############# func function ###########\n");

	printf("value of sig is %d\n",sig);
} 

void (*signal_func(int sig, void (*func_ptr)(int))) (int){

    printf("############# signal_func function ###########\n");

	printf("value of sig is %d and address of func_ptr is %u\n",sig,func_ptr);


	void* (*ptr_sig_func)(int);

	ptr_sig_func = sig_func;

	printf("address of ptr_sig_func is %u\n",ptr_sig_func);


	void * address = (*ptr_sig_func)(20);



	return address;

}

void (*signal_1(int sig, void (*func)(int)))(int){

	void* (*ptr_sig_func)(int);

	ptr_sig_func = sig_func;

	//printf("address of ptr_sig_func is %u\n",ptr_sig_func);


	void * address = (*ptr_sig_func)(20);



	return address;
}


int main(){

	printf("############# main function ##########\n");

  
	printf("address of func is %u\n",func);
	printf("address of sig_func is %u\n",sig_func);

	printf("address of global x is %u\n",&x);
	
      
	printf("address return by signal_func is %u",signal_func(10,func));
	printf("address return by signal_1 is %u",signal_1(10,func));




	return 0;
}


// ############# main function ##########
// address of func is 1286562211
// address of sig_func is 1286562153
// address of global x is 1286574096
// ############# signal_func function ###########
// value of sig is 10 and address of func_ptr is 1286562211
// address of ptr_sig_func is 1286562153
// ############# sig_func function ###########
// value of sig is 20
// address return by signal_func is 1286574096