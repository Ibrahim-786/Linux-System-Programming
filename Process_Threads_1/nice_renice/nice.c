#include<stdio.h>
#include<unistd.h>



// a positive number arg for nice means least priority to run on cpu 
// a negative number arg for nice means high priority to run on cpu 


/*
./nice &

ps -eo 'pid nice args' | grep nice
   4303  19 ./nice
   4306   0 ps -eo pid nice args
   4307   0 grep --color=auto nice


sudo renice 10 -p 4303
[sudo] password for pasha: 
4303 (process ID) old priority 19, new priority 10


ps -eo 'pid nice args' | grep nice
   4303  10 ./nice
   4321   0 ps -eo pid nice args
   4322   0 grep --color=auto nice
*/



int main()
{
	nice(20);


	for(int i =0; i<100000; i++)
	{
		for(int j=0;j<10000000000;j++);
	}

	return 0;
}

