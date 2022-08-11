#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>



int main(int argc , char * argv[])
{
	int fd, temp;
	char buf[16];

	fd = open("test.txt",O_RDONLY);

	while (1)
	{
		for(int i=0;i<5; i++)
		{
			temp = read(fd,buf,(sizeof(buf)-1));

			if(temp != 0)
			{
				buf[temp] = '\0';
				printf("%s\n",buf);
			}
		}

		printf("==== lseeking ======\n");
		lseek(fd, 0, SEEK_SET);
		sleep(1);

	}


	return 0;
}