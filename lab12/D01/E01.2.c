/* 
* @Author: {ZHOU YINAN}
* @Date:   2015-12-23 00:06:48
* @Last Modified by:   mario
* @Last Modified time: 2015-12-23 17:02:11
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
int glo=0;
int main() {

	pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9;
	int p1[2],p2[2],p3[2],p4[2],p5[2],p6[2],p7[2],p8[2],p9[2];
	char tmp,tmp1,tmp2;
	pipe(p1);pipe(p1);pipe(p2);pipe(p3);pipe(p4);pipe(p5);pipe(p6);pipe(p7);pipe(p8);pipe(p9);
	pid1 = fork();
	if(pid1==0)  //A
	{	
		while(1)
	{
		if(glo==0)
		{
			printf("This is process A\n");
			write(p1[1],"A",1);
			write(p2[1],"A",1);
			write(p3[1],"A",1);
			glo=1;
		}
		else
		{
			read(p9[0],&tmp,1);
			printf("This is process A,I got %c from I\n",tmp);
			write(p1[1],"A",1);
			write(p2[1],"A",1);
			write(p3[1],"A",1);
		}
	}

	}
	else
	{
		pid2=fork();
		if(pid2==0) //B
		{
			while(1){
			read(p1[0],&tmp,1);
			printf("This is process B,I got %c from A\n",tmp);
			write(p8[1],"B",1);
			}

		}
		else
		{
			pid3=fork();
			if(pid3==0) //C
			{
				while(1){
				read(p2[0],&tmp,1);
				printf("This is process C,I got %c from A\n",tmp);
				write(p4[1],"C",1);
				write(p5[1],"C",1);
				}

			}
			else
			{	
				pid4=fork();
				if(pid4==0) //D
				{
					while(1){
					read(p3[0],&tmp,1);
					printf("This is process D,I got %c from A\n",tmp);
					write(p7[1],"D",1);
					}
				}
				else
				{
					pid5=fork();
					if(pid5==0) //E
					{
						while(1){
						read(p4[0],&tmp,1);
						printf("This is process E,I got %c from C\n",tmp);
						write(p6[1],"E",1);
						}
					}
					else
					{	
						pid6=fork();
						if(pid6==0) //F
						{
						
							while(1){	
							read(p5[0],&tmp,1);
							printf("This is process F,I got %c from C\n",tmp);
							write(p6[1],"F",1);
							}
						}
						else
						{
							pid7=fork();
							if(pid7==0) //G
							{
								while(1){
								read(p6[0],&tmp,1);
								read(p6[0],&tmp1,1);
								printf("This is process G,I got %c %c from E,F\n",tmp,tmp1);
								write(p8[1],"G",1);
								}
							}
							else
							{
								pid8=fork();
								if(pid8==0) //H
								{
									while(1){
									read(p7[0],&tmp,1);
									printf("This is process H,I got %c from D\n",tmp);
									write(p8[1],"H",1);
									
									}
								}
								else
								{
									pid9=fork();
									if(pid9==0) //I
									{
										while(1){
										read(p8[0],&tmp,1);
										read(p8[0],&tmp1,1);
										read(p8[0],&tmp2,1);
										printf("This is process I,I got %c %c %c form B,G,H\n",tmp,tmp1,tmp2);
										write(p9[1],"I",1);
										}
									}
									else //parent
									{
										sleep(1);
										kill(pid1,SIGKILL);
										kill(pid2,SIGKILL);
										kill(pid3,SIGKILL);
										kill(pid4,SIGKILL);
										kill(pid5,SIGKILL);
										kill(pid6,SIGKILL);
										kill(pid7,SIGKILL);
										kill(pid8,SIGKILL);
										kill(pid9,SIGKILL);
										
									}
								}
							}
						}

					}

				}

			}

		}
	}
    return 0;
}