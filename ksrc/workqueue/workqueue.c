#include <linux/module.h>
#include <linux/init.h>
#include <linux/workqueue.h>
static struct workqueue_struct *queue=NULL;
static struct work_struct   work;
static void work_handler(struct work_struct *data)
{
       printk(KERN_ALERT"work handler function.\n");
}
static int __init test_init(void)
{
      queue = alloc_workqueue("HELLOWORLD", WQ_UNBOUND,1); 
      INIT_WORK(&work,work_handler);
      schedule_work(&work);
	
      return 0;
}
static   void __exit test_exit(void)
{
       destroy_workqueue(queue);
}
MODULE_LICENSE("GPL");
module_init(test_init);
module_exit(test_exit);
