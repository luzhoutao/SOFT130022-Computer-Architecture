#ifndef PIPE_H
#define PIPE_H

//all the users can read and write the memory
#define UGO_RW 0666

//attach the process with the specified cpu
void set_cpu(int cpu_no);

//get a block of shared memory with specified key and size. 
//Here the size is always round to the page size.
//return a shmid which is used by the shmat(shmid) function.
int Shmget(key_t key, size_t size);

//attach the pointer with the specifed shmid.
void* Shmat(int shmid);

//a wrapped function that is composed with Shmget and Shmat,
//it allocate a block of memory and attaches a pointer with it.
//the shmid with the allocated memory is filled in the shmid argument.
void* Shmalloc(key_t key, size_t size, int *shmid);

//free the memory with the specified shmid
void Shmfree(int shmid);

//the wait and set macro. 
//suppose the op is ==, then the wait macro means that wait while var == value.
//the set macro set the var's value to value
volatile int * ___temp_status;  
#define WAIT_WHILE_STATUS(var, op, value)\
	do{\
		___temp_status = &(var);\
		while(*___temp_status op value);\
	}while(0) 

#define SET_STATUS(var, value)\
	__asm__ __volatile__(	\
 		"movl %1, %0\t\n"	\
 		: "=m"(var)		\
 		: "i"(value)		\
 		: "memory")

#endif /* PIPE_H */
