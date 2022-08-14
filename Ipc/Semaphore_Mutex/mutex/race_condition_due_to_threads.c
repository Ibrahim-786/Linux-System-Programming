#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


int shared=1;

void* inc()
{
	int local;

	local = shared;
	printf("Thread1 reads value of shared %d\n",local);
	local++; //thread1 increment its value
	sleep(1); //thread1 is preempted by thread2
	shared = local;//thread1 upadte the value of shared
	printf("Value of shared variable updated by thread1 is %d\n",shared);
	
}

void* dec()
{

	int local;

	local = shared;
	printf("Thread2 reads value of shared %d\n",local);
	local--; //thread2 decrement its value
	sleep(1); //thread2 is preempted by thread1
	shared = local;//thread2 upadte the value of shared
	printf("Value of shared variable updated by thread2 is %d\n",shared);
	

}


int main()
{

	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,inc,NULL);
	pthread_create(&thread2,NULL,dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Final Value of shared is %d\n",shared);
	
	
	return 0;
}
	

