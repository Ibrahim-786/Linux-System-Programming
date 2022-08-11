#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>



int main(int argc,char *argv[])
{

	FILE *fp;

	fp = popen("xargs","w");
	fprintf(fp,"hello world\n");
	fprintf(fp,"hai kalam\n");



	pclose(fp);

	return 0;
}

