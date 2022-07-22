#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>



int main(int argc, char* argv[])
{

       DIR   *dir;
       struct dirent *dent;

       dir = opendir(argv[1]);

       if(dir == NULL)
       {
              perror("opendir failed :");
              exit(1);
       }

       while((dent=readdir(dir))!= NULL)
       {
              printf("%s %d\n",dent->d_name,dent->d_type);

       }
       closedir(dir);
       if(dir == NULL)
       {
              perror("closedir failed");
       }


       return 0;
}

