#include <stdio.h>
#include <stdlib.h>
#include <linux/kernel.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/resource.h>
#include <sys/time.h>
#define NR_mycall 355

int main(void){
		
		printf("pid original = %d\n" ,getpid());
		int y;
		pid_t pid = getpid();
		y = syscall(NR_mycall,pid ,0 );
		pid_t a = fork();
		
		if(a == 0){
				
				pid_t a2 = fork();
				
				if(a2 == 0){
					y = syscall(NR_mycall,getpid() ,0 );
					printf("inner fork1: %d\n", getpid());
					printf("inner fork1 papa : %d\n", getppid());
				}
				else{
					pid_t a3 = fork();
					if(a3 == 0){
						y = syscall(NR_mycall,getpid() ,0 );
						printf("inner fork2: %d\n", getpid());
						printf("inner fork2 papa : %d\n", getppid());
					}
					else{
						printf("cocuk : pid = %d\n" ,getpid());
						printf("cocuk : baba = %d\n" ,getppid());
						wait(NULL);
					}
					wait(NULL);
				}
				
				printf("can i? %d\n" , getpid());
				y = syscall(NR_mycall,getpid() ,0 );
				exit(0);
			
		}
		else {
			printf("pid original = %d\n" ,getpid());
			printf("baba = %d\n" ,getppid());
			wait(NULL);
			
		}

		printf("buraya kadar eristim: %d\n", getpid() ) ;
		
		return 0;
}
