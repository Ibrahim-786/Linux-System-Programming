#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


/* sync
real	0m0.040s
user	0m0.007s
sys	0m0.000s
*/

/* fsync
real	0m0.028s
user	0m0.007s
sys	0m0.000s
*/

/* fdatasync
real	0m0.018s
user	0m0.008s
sys	0m0.000s
*/

/* O_SYNC
real	0m1.676s
user	0m0.001s
sys	0m0.056s
*/



int main(int argc , char * argv[])
{
	
	int fd,temp=0;

	//fd = open("test.txt",O_CREAT | O_WRONLY);
	fd = open("test.txt",O_CREAT | O_WRONLY | O_SYNC);

	if(fd == -1)
	{
		perror("file open failed");
	}

	char buf[8*1024];

	for(int i=0 ;i<1000; i++)
	{
		temp = write(fd,buf,sizeof(buf));
		if(temp == -1)
		{
			perror("write failed");
		}
	}

	close(fd);
	//sync();
	//fsync(fd);
	//fdatasync(fd);


	return 0;
}