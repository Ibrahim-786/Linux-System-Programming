#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void* dummy(void * arg)
{

     int stime = *((int*) arg);

     for(int i =0;i<10;i++)
     {
          sleep(stime);
          printf("[%d] hello world\n",stime);
     }

     return arg;

}


int main(int argc,char* argv[])
{

     pthread_t id1,id2;

     int t1,t2;
     t1=1;
     t2=2;


     int ret1 = pthread_create(&id1,NULL,dummy,(void*)&t1);
     if(ret1 != 0)
     {
          perror("pthread_create() failed");
          exit(1);
     }
     int ret2 = pthread_create(&id2,NULL,dummy,(void*)&t2);
     if(ret2 != 0)
     {
          perror("pthread_create() failed");
          exit(1);
     }

     int re1 = pthread_join(id1, NULL);

     if(re1!=0)
     {
          perror("pthread_join() failed");
     }
     int re2 = pthread_join(id2, NULL);

     if(re2!=0)
     {
          perror("pthread_join() failed");
     }


     return 0;
}