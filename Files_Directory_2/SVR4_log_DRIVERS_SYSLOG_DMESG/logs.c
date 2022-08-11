#include<stdio.h>
#include<unistd.h>
#include<syslog.h>




int main()
{


	openlog("[Virtuq]: ",(LOG_NDELAY|LOG_PERROR),LOG_USER);

	syslog(LOG_ERR,"hello world");
	syslog(LOG_ERR,"hello world %d",2);

return(0);

}

