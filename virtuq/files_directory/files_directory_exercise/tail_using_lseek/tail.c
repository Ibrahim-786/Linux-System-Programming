#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/* mimic tail command using lseek  */

int main(int argc, char* argv[])
{
	int fd;
	int tmp;
	char buf[256];

	fd = open(argv[1],O_RDONLY);

	if(fd == -1)
	{
		perror("file open failed");
		exit(1);
	}
	
	int ret;

	ret = lseek(fd,0,SEEK_END);

	printf("curerent off-set is %d\n",ret);

	int set_tail = ret/2;

	ret = lseek(fd,set_tail,SEEK_SET);

	tmp = read(fd,buf,(sizeof(buf)-1));

	if(tmp == -1)
	{
		perror("read failed");
		exit(1);
	}

	buf[tmp] = '\0';

	printf("file content \n%s\n",buf);

	return 0;
}