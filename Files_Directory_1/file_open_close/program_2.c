#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{

	int fd,temp;
	char c;

	fd = open("/dev/urandom", O_RDONLY  );
	if(fd == -1)
	{
		perror("file open error");
		exit(1);
	}


	for(int i=0; i<10;i++)
	{
		temp = read(fd,&c,sizeof(char));
		if(temp!=0)
		{
			printf("%u ",(unsigned int)c);
		}

	}
	printf("\n");
	close(fd);

	if(fd == -1)
	{
		perror("file close failed ");
	}


	return 0;

}