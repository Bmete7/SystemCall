#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <asm/errno.h>

asmlinkage long set_myflag(pid_t pid, int flag){
	//struct stat sts;
	if(capable(CAP_SYS_ADMIN) ){
		if(flag != 0 && flag != 1){
			return -EINVAL;
		}
	
		struct task_struct *task;
		task = pid_task(find_vpid(pid),PIDTYPE_PID);
		task->myFlag=flag;
	}
	return -EPERM;
}
