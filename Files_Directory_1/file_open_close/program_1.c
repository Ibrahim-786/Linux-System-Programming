#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>




int main(int argc, char* argv[])
{

	int fd,temp;

	fd = open("text.txt",O_CREAT | O_WRONLY | O_ASYNC ,S_IRWXU );
	if(fd == -1)
	{
		perror("file open error");
		exit(1);
	}

	const char buf[] = "#!bin/sh\necho \"hello world\"\n";

	temp = write(fd,buf,sizeof(buf));

	if(temp == -1)
	{
		perror("write error");
		exit(1);
	}
	printf("%s\n",buf);
	printf("number of bytes write to file is : %d\n",temp);

	close(fd);


	return 0;

}