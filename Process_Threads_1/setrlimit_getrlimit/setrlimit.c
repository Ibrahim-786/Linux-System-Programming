#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/resource.h>



// LIMIT_MEMLOCK
//               This is the maximum number of bytes of memory that may be locked into RAM.  This limit is in effect rounded down to the nearest multi‐
//               ple  of  the system page size.  This limit affects mlock(2), mlockall(2), and the mmap(2) MAP_LOCKED operation.  Since Linux 2.6.9, it
//               also affects the shmctl(2) SHM_LOCK operation, where it sets a maximum on the total bytes in shared memory  segments  (see  shmget(2))
//               that  may  be  locked  by the real user ID of the calling process.  The shmctl(2) SHM_LOCK locks are accounted for separately from the
//               per-process memory locks established by mlock(2), mlockall(2), and mmap(2) MAP_LOCKED; a process can lock bytes up to  this  limit  in
//               each of these two categories.

//               In  Linux  kernels before 2.6.9, this limit controlled the amount of memory that could be locked by a privileged process.  Since Linux
//               2.6.9, no limits are placed on the amount of memory that a privileged process may lock, and this limit instead governs the  amount  of
//               memory that an unprivileged process may lock.



int main()
{

	struct rlimit resource1;

	int ret;
	resource1.rlim_cur = 1024;

	resource1.rlim_max = 32768;



	ret = setrlimit(RLIMIT_MEMLOCK,&resource1);


	if(ret != 0)
	{
		perror("setrlimit() failed");

		exit(1);
	}

	 // rlim_t rlim_cur;  /* Soft limit */
     // rlim_t rlim_max;  /* Hard limit 

	printf("RLIMIT_MEMLOCK rlim_cur : [%d]   rlim_max : [%d]",resource1.rlim_cur,resource1.rlim_max);



	return 0;
}