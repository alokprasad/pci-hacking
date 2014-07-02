#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/ioport.h>
// Used To Access KERNEL Macros And Functions
static int Major, result;
struct file_operations fops;
unsigned long start = 0xd260, length = 0x4;
// Parameter to assign value of any variable during loading of module

int memIO_init (void) {
	// Registration of device and dynamic allocation of Major number
	Major = register_chrdev (0, "memIO_device", &fops);
	if (Major < 0)
	{
		printk (" Major number allocation is failed \n");
		return (Major);
	}
	printk (" The Major number of the device is %d \n", Major);
	result = check_region (start, length);
	/* Probes the given address. If the address is already in use, the function will return an
	 * error, otherwise it will allocate the address range for the device. */
	if (result < 0)
	{
		printk ("Allocation for I/O memory range is failed: Try other range\n");
		return (result);
	}
	request_region (start, length, "memIO_device");
	return 0;
}


void memIO_cleanup (void) {
	// Deallocation of I/O memory region before unregistration of the device name
	// and major number
	release_region (start, length);
	printk (" The I/O memory region is released successfully \n");
	unregister_chrdev (Major, "memIO_device");
	printk (" The Major number is released successfully \n");
}

module_init (memIO_init);
module_exit (memIO_cleanup);

MODULE_LICENSE("GPL");

