#include <stdio.h>
#include <stdlib.h>


typedef union {
	int num;
	char bytes[4];

}endiens;

/*
store value 10 in memory
4 byte number 
 0000 | 0000 | 0000 | 0000 
if little endian
 0000 | 0000 | 0000 | 1010
if big endian
 1010 | 0000 | 0000 | 0000

*/

int main(int argc, char * argv[] )
{

 	endiens var;

 	var.num =10;


 	printf("after a long time hello programming\n");

 	printf("4 byte number :%d\n",var.num);

 	for(int i=0 ; i<4; i++){
 		printf("%d bytes :%d\n",i,var.bytes[i]);

 	}


	if(var.bytes[0]!=0){
 			printf("these machine is little endian mostly x86\n");
 		}


 	return 0;
}