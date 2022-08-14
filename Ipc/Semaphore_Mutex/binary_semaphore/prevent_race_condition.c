#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include <semaphore.h>


int shared=1;

sem_t sem_var; //semaphore variable

void* inc()
{
	int local;
	sem_wait(&sem_var);// if 0 wait for update from sem_post to make 1
	local = shared;
	printf("Thread1 reads value of shared %d\n",local);
	local++; //thread1 increment its value
	sleep(1); //thread1 is preempted by thread2
	shared = local;//thread1 upadte the value of shared
	printf("Value of shared variable updated by thread1 is %d\n",shared);

	sem_post(&sem_var);//make semaphore value to 1 
	
}

void* dec()
{

	int local;
	sem_wait(&sem_var);
	local = shared;
	printf("Thread2 reads value of shared %d\n",local);
	local--; //thread2 decrement its value
	sleep(1); //thread2 is preempted by thread1
	shared = local;//thread2 upadte the value of shared
	printf("Value of shared variable updated by thread2 is %d\n",shared);
	sem_post(&sem_var);

}



int main()
{

/* 1st argument is address of variable
   2nd variable is number 0  to use semaphore between thread and 1 to use semaphore between process
   3rd argument is initial value of semaphore like 0/1
   0 means resource is busy wait 
   1 means resource is free */

 
	sem_init(&sem_var,0,1);
	
	pthread_t thread1,thread2;

	pthread_create(&thread1,NULL,inc,NULL);
	pthread_create(&thread2,NULL,dec,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("Final Value of shared is %d\n",shared);
	
	
	return 0;
}
	

