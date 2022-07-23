#include<stdio.h>
#include<dlfcn.h>
#include <stdlib.h>

void (*shared_pointer)(void);




int main()
{

	void *dl;

	dl  = dlopen("libfunc.so",RTLD_LAZY);

	if(!dl)
	{
		fprintf(stderr," %s\n",dlerror());
		exit(1);
	}

	shared_pointer = dlsym(dl,"sahred_func");

	shared_pointer();

	return 0;
}









