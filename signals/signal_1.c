#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>




void catch_sig(int sig_num){

	signal(sig_num,catch_sig);
	printf("catch_sig %d",sig_num);

	exit(1);
}

//SIG_IGN means igonore the signal
//SIG_DFL means perform default action
//cath_sig mean catch these signal and perform operation specified in catch_sig function 
int main(){



	signal(SIGTERM,SIG_IGN);
	//signal(SIGINT,catch_sig);
	int arr[2];
	arr[6] = 10;

	//signal(SIGSEGV,catch_sig);
	//pause();
	
	



}

