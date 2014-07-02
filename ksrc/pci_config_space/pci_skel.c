/* PCI skeleton driver - for e1000 device 
 * Hello World Program to Understand PCI Module Programming.
 * This program mainly show probe being called when a matching device is called.
 * Here read_config_space is invoked to read varioous config space registers.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
/* The register addresses are stored here */
#include <linux/pci_regs.h>
#include <linux/init.h>

static struct pci_device_id ids[] = {
	/* Device ID and vendor ID for e1000 device */
	{ PCI_DEVICE(0x8086, 0x100E), },
	/* Below is the sample device ID and vendor ID */
	{ PCI_DEVICE(PCI_VENDOR_ID_INTEL, PCI_DEVICE_ID_INTEL_82801AA_3), },
	{ 0, }
};

static void read_config_space(struct pci_dev *dev)
{
	u8 int_line, int_pin, revision;
	u16 vendor_id, device_id;
	u32 bar[6];

	pci_read_config_word(dev, PCI_VENDOR_ID, &vendor_id);
	printk(KERN_INFO "PCI_VENDOR_ID : 0x%x\n", vendor_id);

	pci_read_config_word(dev, PCI_DEVICE_ID, &device_id);
	printk(KERN_INFO "PCI_DEVICE_ID : 0x%x \n", device_id);

	pci_read_config_byte(dev, PCI_REVISION_ID, &revision);
	printk(KERN_INFO "PCI_REVISION_ID : 0x%d \n", revision);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_0, &bar[0]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_0 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_0, bar[0]);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_1, &bar[1]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_1 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_1, bar[1]);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_2, &bar[2]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_2 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_2, bar[2]);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_3, &bar[3]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_3 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_3, bar[3]);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_4, &bar[4]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_4 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_4, bar[4]);

	pci_read_config_dword(dev, PCI_BASE_ADDRESS_5, &bar[5]);
	printk(KERN_INFO "BASE_ADDRESS_REGISTER_5 - 0x%.8x, VAL : 0x%x\n", PCI_BASE_ADDRESS_5, bar[5]);

	pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &int_line);
	printk(KERN_INFO "PCI_INTERRUPT_LINE : %d \n", int_line);

	pci_read_config_byte(dev, PCI_INTERRUPT_PIN, &int_pin);
	printk(KERN_INFO "PCI_INTERRUPT_PIN : %d \n", int_pin);

	return;
}

/* kernel builds a table during build time in
   /lib/modules/<kern>modules.pcimap that which
   driver is supported for particular pci_vendor
 */
//MODULE_DEVICE_TABLE(pci,pci_tbl);

/*  1. 	Probe is called if a matching device in pci_tbl is found in the
 *  	the  System ,Called once for each matching device .if already called
 *  	another module , probe will not be called.
 *  2. 	when in Sysfs bind and new_id macthcing id found then Also probe is called
 */
static int probe(struct pci_dev *dev, const struct pci_device_id *id)
{
	/* Do the probe stuff here */
	
	printk(KERN_INFO "*** inside probe - (pci_my_skel) *** \n");
	
	read_config_space(dev);

	return 0;
}

static void remove(struct pci_dev *dev)
{
	/* clean up done here */
}

/*pci driver operation */
static struct pci_driver pci_driver = {
	.name = "pci_my_skel",
	.id_table = ids,
	.probe = probe,
	.remove = remove,
};

/*called while loading driver*/
static int __init pci_skel_init(void)
{
	/*register the pci_driver structure with pci subsystem*/
	printk(KERN_INFO "*** inside init - (pci_my_skel) *** \n");

	return pci_register_driver(&pci_driver);
}

/*called while rmmod or unbind from sysfs*/
static void __exit pci_skel_exit(void)
{
	printk(KERN_INFO "*** inside exit - (pci_my_skel) *** \n");

	pci_unregister_driver(&pci_driver);
}

MODULE_LICENSE("GPL");

module_init(pci_skel_init);
module_exit(pci_skel_exit);
