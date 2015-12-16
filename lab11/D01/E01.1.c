/* 
* @Author: mario
* @Date:   2015-12-15 21:21:03
* @Last Modified by:   mario
* @Last Modified time: 2015-12-15 21:50:42
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void func();
int main() {	

	pid_t pid1,pid2;
	int def_pipe[2];
	pipe(def_pipe);
	printf("Prcocessing, I am process A\n");
	pid1=fork();
	if(pid1==0)   //process B
	{
		printf("I am pricess B\n");
		write(def_pipe[1],"B",strlen("B"));
		exit(0);
	}
	else
	{
		pid2=fork();
		if(pid2==0) //Process D
		{
			printf("I am process D\n");
			sleep(1);
			printf("I am process H\n");
			write(def_pipe[1],"H",strlen("H"));
			exit(0);
		}
		else //process C
		{	
			printf("I am process C\n");
			func();
			printf("I am process G\n");

		}
	}

	char temp1[10];
	char temp2[10];
	read(def_pipe[0],temp1,strlen("G"));
	read(def_pipe[0],temp2,strlen("H"));
	printf("I am process I, I read from pipe : %s,%s\n",temp1,temp2);



    return 0;
}

void func()
{
	pid_t pid;
	int file_pipes[2];
	pipe(file_pipes);
	char temp[50];
	pid = fork();
	if(pid==0)
	{
		write(file_pipes[1],"Hello",strlen("Hello"));
		exit(0); //child process stops here
	}
	else
	{
		read(file_pipes[0],temp,50);
		
	}
}