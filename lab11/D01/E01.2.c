/* 
* @Author: mario
* @Date:   2015-12-15 22:10:02
* @Last Modified by:   mario
* @Last Modified time: 2015-12-15 23:03:57
*/

#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"
#include "semaphore.h"

sem_t *sem1,*sem2;
void*handler(void*argv);
void*handler_B(void*argv);
void*handler_C(void*argv);
void*handler_D(void*argv);
void*handler_H(void*argv);


void * handler_B(void*arg)
{
	printf("This is thread B\n");
	sem_post(sem1);
	return 0;
}
void * handler_C(void*arg)
{
	printf("This is thread C\n");
	pthread_t th_e,th_f;
	sem2=(sem_t*)malloc(sizeof(sem_t));
	sem_init(sem2,0,0);
	pthread_create(&th_e,NULL,handler,0);
	pthread_create(&th_f,NULL,handler,0);
	sem_wait(sem2);
	sem_wait(sem2);
	printf("Now I am G\n");
	sem_post(sem1);
	return 0;
}
void * handler_D(void*arg)
{
	printf("This is thread D\n");
	pthread_t th_h;
	pthread_create(&th_h,NULL,handler_H,0);
	return 0;
}
void * handler_H(void*arg)
{
	printf("This thread H\n");
	sem_post(sem1);
	return 0;
}
void * handler(void *arg)
{
	printf("Doing some stuff...\n");
	sem_post(sem2);
	return 0;

}
int main() {

	pthread_t th_b,th_c,th_d;
	sem1=(sem_t*)malloc(sizeof(sem_t));
	sem_init(sem1,0,0);
	 printf("Processing...\n");
	 pthread_create(&th_b,NULL,handler_B,0);
	 pthread_create(&th_c,NULL,handler_C,0);
	 pthread_create(&th_d,NULL,handler_D,0);
	 sem_wait(sem1);
	 sem_wait(sem1);
	 sem_wait(sem1);
	printf("Now everything is done...\n");

    return 0;
}
