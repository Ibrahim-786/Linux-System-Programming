#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include<string.h>

#define MAX_SIZE 1024
 
// Locking mechanism
pthread_mutex_t lock;
 
int shmid;
 
void *ptr;

char buffer[100];

void getData()
{
    pthread_mutex_lock(&lock);
 
    printf("Data read from memory: %s\n",(char *) ptr);
    shmdt(ptr);
    pthread_mutex_unlock(&lock);
}

void storeData(int arg)
{
	
        pthread_mutex_lock(&lock);
	//printf("Enter the data\n");
	//read(0,buffer,100);
	strcpy(ptr,"shared memory data");
	printf("data store to the memory: %s\n",(char *)ptr);
	shmdt(ptr);
        pthread_mutex_unlock(&lock);
}
 
int main()
{

    key_t key = ftok("shmfile", 65);
 
    shmid = shmget(key, MAX_SIZE, 0666 | IPC_CREAT);
 
    ptr = shmat(shmid,NULL, 0);

    printf("shmat address: %p\n", ptr);
 
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);

    int pid = fork();
 
    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
 
    if (pid == 0)
    {
       // storeData(shmid);
       // Get data from shared memory
        getData();
	
    }
 
    else
    {
        // Wait for child process to complete
        // wait(NULL);
 
        // Store data in shared memory
        storeData(shmid);
       // getData();
        
        // Detach the shared memory
       // shmdt(ptr);
    }
 
    return 0;
}


