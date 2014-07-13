/*
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/sysfs.h>
#include <linux/fs.h>
#include <linux/kobject.h>
#include <linux/device.h>
#include <linux/proc_fs.h>
#include <linux/types.h>
#include <linux/pci.h>
#include <linux/version.h>
#include<linux/kernel.h>


#define PCI_VENDOR_ID_XTREME		0x15b3
#define PCI_DEVICE_ID_XTREME_VNIC	0x1450

static struct pci_bus *vbus;
static struct pci_sysdata *sysdata;

static DEFINE_PCI_DEVICE_TABLE( vpci_dev_table) = {
	{PCI_DEVICE(PCI_VENDOR_ID_XTREME, PCI_DEVICE_ID_XTREME_VNIC)},
	{0}
};

MODULE_DEVICE_TABLE(pci,  vpci_dev_table);

int  vpci_read(struct pci_bus *bus, unsigned int devfn, int where,
		 int size, u32 *val)
{
	switch (where) {
	case PCI_VENDOR_ID:
		*val = PCI_VENDOR_ID_XTREME | PCI_DEVICE_ID_XTREME_VNIC << 16;
		/* our id */
		break;
	case PCI_COMMAND:
		*val = 0;
		break;
	case PCI_HEADER_TYPE:
		*val = PCI_HEADER_TYPE_NORMAL;
		break;
	case PCI_STATUS:
		*val = 0;
		break;
	case PCI_CLASS_REVISION:
		*val = (4 << 24) | (0 << 16) | 1;
		/* network class, ethernet controller, revision 1 */ /*2 or 4*/
		break;
	case PCI_INTERRUPT_PIN:
		*val = 0;
		break;
	case PCI_SUBSYSTEM_VENDOR_ID:
		*val = 0;
		break;
	case PCI_SUBSYSTEM_ID:
		*val = 0;
		break;
	default:
		*val = 0;
		/* sensible default */
	}
	return 0;
}

int  vpci_write(struct pci_bus *bus, unsigned int devfn, int where,
		  int size, u32 val)
{
	switch (where) {
	case PCI_BASE_ADDRESS_0:
	case PCI_BASE_ADDRESS_1:
	case PCI_BASE_ADDRESS_2:
	case PCI_BASE_ADDRESS_3:
	case PCI_BASE_ADDRESS_4:
	case PCI_BASE_ADDRESS_5:
		break;
	}
	return 0;
}

struct pci_ops  vpci_ops = {
	.read =  vpci_read,
	.write =  vpci_write
};


void  vpci_remove_vnic()
{
	struct pci_dev *pcidev = NULL;
	if (vbus == NULL)
		return;
	pci_remove_bus_device(pcidev);
	pci_dev_put(pcidev);
}
EXPORT_SYMBOL( vpci_remove_vnic);

void  vpci_vdev_remove(struct pci_dev *dev)
{
}

static struct pci_driver  vpci_vdev_driver = {
	.name = "Xtreme-Virtual-NIC1",
	.id_table =  vpci_dev_table,
	.remove =  vpci_vdev_remove
};

int  vpci_bus_init(void)
{
	struct pci_dev *pcidev = NULL;
	sysdata = kzalloc(sizeof(void *), GFP_KERNEL);
		vbus = pci_scan_bus_parented(NULL, 2, & vpci_ops, sysdata);
		//vbus = pci_create_root_bus(NULL,i,& vpci_ops, sysdata,NULL);
		//if (vbus != NULL)
			//break;
		memset(sysdata, 0, sizeof(void *));
	if (vbus == NULL) {
		kfree(sysdata);
		return -EINVAL;
	}
	if (pci_register_driver(& vpci_vdev_driver) < 0) {
		pci_remove_bus(vbus);
		vbus = NULL;
		return -EINVAL;
	}
	pcidev = pci_scan_single_device(vbus, 0);

        if (pcidev == NULL)
                return 0;
        else
                pci_dev_get(pcidev);
	
	pci_bus_add_devices(vbus);
	
	return 0;
}

void  vpci_bus_remove(void)
{
	if (vbus) {
		pci_unregister_driver(&vpci_vdev_driver);
		device_unregister(vbus->bridge);
		pci_remove_bus(vbus);
		kfree(sysdata);
		vbus = NULL;
	}
}


static int __init pci_init(void)
{
	printk( "module loaded");
	 vpci_bus_init();
	return 0;
}

static void __exit pci_exit(void)
{
        printk(KERN_ALERT "unregister PCI Device\n");
        pci_unregister_driver(&vpci_vdev_driver);
}


module_init(pci_init);
module_exit(pci_exit);
MODULE_LICENSE("GPL");

