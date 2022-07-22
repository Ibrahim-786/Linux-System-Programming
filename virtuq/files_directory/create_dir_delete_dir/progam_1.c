#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>           
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>


/* here pasha_dir is created and deleted during the execution of program */


int main(int argc, char * argv[])
{

       int ret_val;

       ret_val = mkdir("pasha_dir", S_IRWXU);

       if(ret_val == -1)
       {
              perror("mkdir failed");
              exit(1);
       }

       ret_val = rmdir("pasha_dir");

       if(ret_val == -1)
       {
              perror("remove directory failed");
       }

       return 0;
}
