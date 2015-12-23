/* 
* @Author: {ZHOU YINAN}
* @Date:   2015-12-23 00:17:43
* @Last Modified by:   mario
* @Last Modified time: 2015-12-23 16:31:24
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main() {

	pid_t pid1,pid2,pid3,pid4,pid5,pid6,pid7,pid8,pid9;
	int p1[2],p2[2],p3[2],p4[2],p5[2];
	char tmp[20];
	pipe(p1);pipe(p1);pipe(p2);pipe(p3);pipe(p4);pipe(p5);
	pid1 = fork();
	if(pid1==0)  //A
	{	
		printf("This is process A\n");
		write(p1[1],"A",1);
		write(p1[1],"A",1);
		write(p1[1],"A",1);
		exit(0);

	}
	else
	{
		pid2=fork();
		if(pid2==0) //B
		{
			read(p1[0],&tmp[0],1);
			printf("This is process B,I got %c from A\n",tmp[0]);
			write(p5[1],"B",1);
			//exit(0);

		}
		else
		{
			pid3=fork();
			if(pid3==0) //C
			{
				read(p1[0],&tmp[1],1);
				printf("This is process C,I got %c from A\n",tmp[1]);
				write(p2[1],"C",1);
				write(p2[1],"C",1);
				exit(0);

			}
			else
			{	
				pid4=fork();
				if(pid4==0) //D
				{
					read(p1[0],&tmp[2],1);
					printf("This is process D,I got %c from A\n",tmp[2]);
					write(p3[1],"D",1);
					exit(0);
				}
				else
				{
					pid5=fork();
					if(pid5==0) //E
					{
						read(p2[0],&tmp[3],1);
						printf("This is process E,I got %c from C\n",tmp[3]);
						write(p4[1],"E",1);
						exit(0);
					}
					else
					{	
						pid6=fork();
						if(pid6==0) //F
						{
							read(p2[0],&tmp[4],1);
							printf("This is process F,I got %c from C\n",tmp[4]);
							write(p4[1],"F",1);
							exit(0);
						}
						else
						{
							pid7=fork();
							if(pid7==0) //G
							{
								read(p4[0],&tmp[5],1);
								read(p4[0],&tmp[6],1);
								printf("This is process G,I got %c %c from E,F\n",tmp[5],tmp[6]);
								write(p5[1],"G",1);
								//exit(0);
							}
							else
							{
								pid8=fork();
								if(pid8==0) //H
								{
									read(p3[0],&tmp[7],1);
									printf("This is process H,I got %c from D\n",tmp[7]);
									write(p5[1],"H",1);
									
									//exit(0);
								}
								else
								{
									pid9=fork();
									if(pid9==0) //I
									{
										read(p5[0],&tmp[8],1);
										read(p5[0],&tmp[9],1);
										read(p5[0],&tmp[10],1);
										printf("This is process I,I got %c %c %c form B,G,H\n",tmp[8],tmp[9],tmp[10]);
										exit(0);
									}
									else //parent
									{
										sleep(3);
										printf("I am the parent, hahaha!\n");
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