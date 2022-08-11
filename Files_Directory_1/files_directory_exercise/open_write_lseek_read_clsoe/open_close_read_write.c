#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>



/*  learning from these program is file descriptor keep on move when we do read/write opeartion
	so we need lseek to set the offset to to begining of the file */



int main(int argc, char* argv[])
{

	int fd,tmp;
	off_t ret;

	fd =  open("new_test.txt", O_CREAT | O_RDWR );

	if(fd == -1)
	{
		perror("open failed");
		exit(1);
	}

	char write_buf[256]= "ibrahim pasha";
	char read_buf[256];

	memset(read_buf,0,256);

	tmp = 0;
	tmp = write(fd,write_buf,sizeof(write_buf));

	if(tmp == -1)
	{
		perror("write failed");
		exit(1);
	}
	printf("number of bytes write is  : %d\n",tmp);
	

	ret =lseek(fd,0,SEEK_SET);
	printf("present offset after reset %ld\n",ret);

	tmp = read(fd,read_buf,7);

	if(tmp == -1)
	{
		perror("read failed");
		exit(1);
	}

	read_buf[tmp] = '\0';

	printf("number of bytes read is  : %d and string is %s\n",tmp,read_buf);


	close(fd);

	if(fd == -1)
	{
		perror("close failed");
	}	

	return 0;
}