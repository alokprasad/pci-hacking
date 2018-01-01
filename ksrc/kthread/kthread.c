#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#define THREAD_NAME "my_thread"

struct task_struct *task;

int my_thread(void *data){

	allow_signal(SIGKILL);
	while(1) {
		
		ssleep(1);
		pr_err("Printing in Loop every sec in kernel thread\n");
		if (kthread_should_stop()) break;
		if (signal_pending(task)) { printk("SIGKILL called \n" );break;}
	}
	return 0;
}

static int thread_init(void){
	printk(KERN_INFO "Starting Kernel thread...");
	task = kthread_run(my_thread, NULL, THREAD_NAME);
}  

void thread_exit(void){
	kthread_stop(task);
	printk(KERN_INFO "stopping thread done.");
}

module_init(thread_init);
module_exit(thread_exit);
//MODULE_LICENSE("GPL");
