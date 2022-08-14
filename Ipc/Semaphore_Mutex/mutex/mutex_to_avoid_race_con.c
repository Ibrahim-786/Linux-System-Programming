#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>


int shared=1;

pthread_mutex_t mutex_var; //mutex variable

void* inc()
{
	int local;
	printf("thread1 is trying to acquire lock \n");

	pthread_mutex_lock(&mutex_var);/*thread1 is acquired the lock, now thread2 will not be able
	to acquire lock until it it unlocked by thread 1 */
	
		local = shared;
		printf("Thread1 reads value of shared %d\n",local);
		local++; //thread1 increment its value
		sleep(1); //thread1 is preempted by thread2
		shared = local;//thread1 upadte the value of shared
		printf("Value of shared variable updated by thread1 is %d\n",shared);

	pthread_mutex_unlock(&mutex_var);
	printf("thread1 released the lock\n");
	
}

void* dec()
{

	int local;
	printf("thread2 is trying to acquire lock\n");
	pthread_mutex_lock(&mutex_var);
		printf("Thread2 acquired lock\n");
		local = shared;
		printf("Thread2 reads value of shared %d\n",local);
		local--; //thread2 decrement its value
		sleep(1); //thread2 is preempted by thread1
		shared = local;//thread2 upadte the value of shared
		printf("Value of shared variable updated by thread2 is %d\n",shared);
	

	pthread_mutex_unlock(&mutex_var);
	printf("thread2 released the lock\n");
	
}



int main()
{

/* 1st argument is mutex variable 
   2nd argument is specifies attributes for mutex lock   */

	pthread_mutex_init(&mutex_var,NULL);
	
	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,inc,NULL);
	pthread_create(&thread2,NULL,dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Final Value of shared is %d\n",shared);
	
	
	return 0;
}
	

