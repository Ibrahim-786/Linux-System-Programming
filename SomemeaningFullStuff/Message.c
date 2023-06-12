#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <signal.h>



#define MAX 256

int writter(int msg_id);
int reader(int msg_id);
void store_data (void);
void sig_handler(int n);

struct message {
  long mesg_type;
  char mesg_text[256];
} ;
int msg_id;
int main()
{

	key_t key=1234;
	int pid;
	msg_id =msgget(key,0666|IPC_CREAT);
	printf("msg id ==%d\n",msg_id);
	if(msg_id==-1)
	{
		perror("error for msg id\n");
		exit(0);
	}
	pid =fork();

	if(pid==0)
	{
		printf("child sending message\n");
		kill(getppid(), SIGKILL);
		reader(msg_id);
		store_data();
	}

	else
	{

		signal(SIGKILL,sig_handler);
		sleep(5);
	}
	msgctl(msg_id,IPC_RMID,NULL);
	return 0;
}


int writter(int mesg_id)
{
	struct message m ;
	m.mesg_type=1;
	fgets(m.mesg_text,MAX,stdin);
	//strcpy(m.msg_text,"hello good noon");
	if(msgsnd(mesg_id,&m,strlen(m.mesg_text),0)==-1)
	{
		perror("error while sending\n");
		exit(1);
	}
	printf("msg sent\n");
}


int reader(int mesg_id)
{
	struct message m ;
	int n;
	int length;
	msgrcv(mesg_id,&m,MAX,1,0);
	printf("text recied from parent is %s\n",m.mesg_text);

}
void store_data(void)
{
	struct message m ;
	FILE *f;

	printf("msg =====%s\n",m.mesg_text);
	printf("-----storing into text file----\n");
        f=fopen("message_queue.txt","a");

        fprintf(f,"%s",m.mesg_text);
        fclose(f);

}
void sig_handler(int n)
{
	printf("signale is sending to child\n");
	writter(msg_id);
}

