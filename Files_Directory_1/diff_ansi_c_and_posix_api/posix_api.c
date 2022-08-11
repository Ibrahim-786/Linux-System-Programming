#include <stdio.h>  /* for printf and scanf */
#include <unistd.h> /*for open and write  */
#include <fcntl.h>  /*for O_CREAT O_RD O_WR */
#include <stdlib.h> /*for exit(1) */



int main(int argc, char* argv[])
{

	int fd,i;

	fd= open("test_1.txt",O_CREAT | O_WRONLY | O_ASYNC);

	if(fd == -1){
		perror("file create error");
		exit(1);
	}

	const char buf[4*16*256];

	for(i=0; i<10*10*1000/4; i++)
	{
		write(fd,buf,sizeof(buf));
	}


	close(fd);

	return 0;
}