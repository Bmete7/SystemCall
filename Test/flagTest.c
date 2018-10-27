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
		y = syscall(NR_mycall,pid ,1 );
		pid_t a = fork();
		if(a == 0){
				printf("cocuk : pid = %d\n" ,getpid());
				printf("cocuk : baba = %d\n" ,getppid());
				exit(0); 
		}
		else {
			printf("pid original = %d\n" ,getpid());
			printf("baba = %d\n" ,getppid());
			wait(NULL);
		}

		
		
		return 0;
}
