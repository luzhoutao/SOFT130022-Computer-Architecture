/*
 *  this is for the do-pipe program 	
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <string.h>
#include <sched.h>

#include "pipe.h"

void set_cpu(int cpu_no)
{
	unsigned long cpumask;
	cpumask = 1 << cpu_no;
	sched_setaffinity(getpid(), sizeof(unsigned long), &cpumask);
}

int Shmget(key_t key, size_t size)
{
	int shmid = shmget(key, size, IPC_CREAT |UGO_RW);
	if(shmid < 0)
	{
		printf("Error with key %d\n", key);
		if(errno == EACCES)
	 		printf("Error EACCES\n");
	 	else if(errno == EEXIST)
	 		printf("Error EEXIST\n");
	 	else if(errno == ENOENT)
	 		printf("Error ENOENT\n");
	 	else if(errno == ENOMEM)
	 		printf("Error ENOMEM\n");
	 	else if(errno == ENOSPC )
 			printf("Error ENOSPC\n");
		else if(errno ==  EINVAL )
 			printf("Error  EINVAL\n");
		perror("shmget error");
		exit(-1);
	}
	return shmid;
}

void* Shmat(int shmid)
{
	void* addr = shmat(shmid, NULL, 0);
	if(addr == (void *)(-1))
	{
		printf("Error with shmid %d\n", shmid);
		if(errno == EACCES)
	 		printf("Error EACCES\n");
		else if(errno ==  EINVAL )
 			printf("Error  EINVAL\n");
	 	else if(errno == ENOMEM)
	 		printf("Error ENOMEM\n");
		perror("shmat error");
		exit(-1);
	}
	return addr;
}

void* Shmalloc(key_t key, size_t size, int *shmid)
{
	int id = Shmget(key, size);
	*shmid = id;
	void *addr = Shmat(id);
	memset(addr,0,size);
	return addr;
}

void Shmfree(int shmid)
{
	if(shmctl(shmid, IPC_RMID, NULL) < 0)
	{
		printf("Error with shmid %d\n", shmid);
		if(errno == EACCES)
	 		printf("Error EACCES\n");
	 	else if(errno == EFAULT)
	 		printf("Error EFAULT\n");
	 	else if(errno == EIDRM)
	 		printf("Error EIDRM\n");
		else if(errno ==  EINVAL )
 			printf("Error  EINVAL\n");
		else if(errno == ENOMEM)
	 		printf("Error ENOMEM\n");
	 	else if(errno == EOVERFLOW )
 			printf("Error EOVERFLOW\n");
	 	else if(errno == EPERM )
 			printf("Error EPERM\n");
		perror("shmctl error");
		exit(-1);
	}
}
