#include <stdio.h>


int main(int argv, char* argc[])
{

	FILE *fp;
	int i;
	char buf[16];

	const int bf_sz = sizeof(buf);

	fp = fopen("test.txt","w");

	for(i=0;i<bf_sz-1;i++)
	{
		buf[i] = 'A';
	}
	buf[bf_sz-1]='\0';

	for(i=0;i<10*10*1000*256;i++)
	{
		fputs(buf,fp);
	}

	fclose(fp);



	return 0;
}

