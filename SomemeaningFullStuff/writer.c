#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/stat.h>

int main(){
	//ftok to generate the unique key
	key_t key =ftok("f1.txt",65);

	//shmget returns an identifier in shmid
		int shmid=shmget(key, 1024, 0666|IPC_CREAT);
	
		//shmat to attach to shared memory
		char *buffer = (char*) shmat (shmid, NULL, 0);

		printf("please enter a string to be written in shared memory:\n");
		fgets(buffer, 512,stdin);
		printf("Data has been written in shared memory.bye\n");

		//detachfrom shared memory
		shmdt(buffer);
		return 0;
}



