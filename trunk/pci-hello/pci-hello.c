/* Hello World Program to Understand PCI Module Programming, This
 * Program mainly show probe being called when a matching device 
 * is called.
 * Also probe can read config byte as it is reading device at offset
 * at 0x02 of configuration space
*/

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/pci.h>
#include<linux/init.h>


static struct pci_device_id pci_tbl[] =
{
	/* VENDOR ID, DEVICE ID */
	{PCI_DEVICE(0x8086,0x100e)},
	/*required last entry*/
	{0},

};

/* kernel builds a table during build time  in 
   /lib/modules/<kern>modules.pcimap that which 
   driver is supported for particular pci_vendor
 */
//MODULE_DEVICE_TABLE(pci,pci_tbl);

/* 1. Probe is called if a matching device in pci_tbl is found in the 
 *  the  System ,Called once for each matching device .if already called
 *  another module , probe will not be called.
 *  2. when in Sysfs bind and new_id macthcing id found then Also probe is 
 *  called
 */
static int probe(struct pci_dev *pdev,const struct pci_device_id *id)
{
	uint16_t deviceid;
	//ret = pci_enable_device(pdev);

	/*read configuration byte */
	pci_read_config_word(pdev,0x02,&deviceid);
	printk("deviceid =%d\n",deviceid);

	/*read some configuration register*/
	return 0;

}

static void remove(struct pci_dev *pdev)
{

	printk("Removed Called\n");	

}

/*pci driver operation */
static struct pci_driver pci_driver_ops = {
	.name = "pci_e1000", /*Create entry in sysbus */
	.id_table = pci_tbl,
	.probe = probe,
	.remove = NULL,
	.suspend = NULL,
	.resume = NULL,
};

/*called while loading driver*/
static int __init pci_init(void)
{	
	/*register the pci_driver structure with pci subsystem*/
	printk(KERN_ALERT "register PCI Device\n");
	pci_register_driver(&pci_driver_ops);
	return 0;
}

/*called while rmmod or unbind from sysfs*/
static void __exit pci_exit(void)
{
	printk(KERN_ALERT "unregister PCI Device\n");
	pci_unregister_driver(&pci_driver_ops);
}

MODULE_LICENSE("GPL");
module_init(pci_init);
module_exit(pci_exit);
