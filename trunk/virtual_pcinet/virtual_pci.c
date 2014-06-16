/*
 */

#include <linux/version.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/sysfs.h>
#include <linux/syscalls.h>
#include <linux/fs.h>
#include <linux/kobject.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/proc_fs.h>
#include <linux/types.h>
#include <linux/kobject.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/pci.h>
#include <asm/scatterlist.h>
#include <asm/io.h>
#include <linux/in.h>
#include <linux/log2.h>
#include <linux/mutex.h>
#include <linux/version.h>
#include <linux/netdevice.h>



#define PCI_VENDOR_ID_XTREME		0x8086
#define PCI_DEVICE_ID_XTREME_VNIC	0x1000

static struct pci_bus *vbus;
static struct pci_sysdata *sysdata;

static DEFINE_PCI_DEVICE_TABLE(xt_vpci_dev_table) = {
	{PCI_DEVICE(PCI_VENDOR_ID_XTREME, PCI_DEVICE_ID_XTREME_VNIC)},
	{0}
};

MODULE_DEVICE_TABLE(pci, xt_vpci_dev_table);

int xt_vpci_read(struct pci_bus *bus, unsigned int devfn, int where,
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
		*val = (2 << 24) | (0 << 16) | 1;
		/* network class, ethernet controller, revision 1 */
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

int xt_vpci_write(struct pci_bus *bus, unsigned int devfn, int where,
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

struct pci_ops xt_vpci_ops = {
	.read = xt_vpci_read,
	.write = xt_vpci_write
};

struct pci_dev *xt_vpci_prep_vnic(struct net_device *netdev, char *vnic_name,
				  int devn)
{
	struct pci_dev *pcidev = NULL;
	/* netdev->ifindex always comes as zero
	* for rhel5 versions before registration
	*/

	//if (!boot_flag || vbus == NULL)
	//	return NULL;

	pcidev = pci_scan_single_device(vbus, devn);

	if (pcidev == NULL)
		return NULL;
	else
		pci_dev_get(pcidev);

	pci_bus_add_devices(vbus);
	SET_NETDEV_DEV(netdev, &pcidev->dev);
	return pcidev;
}
EXPORT_SYMBOL(xt_vpci_prep_vnic);

void *xt_vpci_add_vnic(char *vnic_name, int devn)
{
	struct pci_dev *pcidev;
	struct net_device *netdev;
	int ret;
	//ALOK
	netdev = alloc_netdev(1, "xsvnic%d", ether_setup);
	xt_vpci_prep_vnic(netdev,"XSVNIC",0);
	if (vbus == NULL)
		return NULL;
	pcidev = pci_scan_single_device(vbus, devn);
	if (pcidev == NULL)
		return NULL;
	else
		pci_dev_get(pcidev);
	/*
	 * Better to use compat layer, but for now since this is citrix specific
	 * will use LINUX version magic
	 */
	netdev = dev_get_by_name(&init_net, vnic_name);
	if (netdev == NULL) {
		pci_dev_put(pcidev);
		return NULL;
	}
	if (pci_bus_add_device(pcidev) != 0) {
		dev_put(netdev);
		pci_dev_put(pcidev);
		return NULL;
	}

	ret = sysfs_create_link(&netdev->dev.kobj, &pcidev->dev.kobj, "device");
	if (ret) {
		pci_remove_bus_device(pcidev);
		dev_put(netdev);
		pci_dev_put(pcidev);
		pcidev = NULL;
	}
	return pcidev;
}
EXPORT_SYMBOL(xt_vpci_add_vnic);

void xt_vpci_remove_vnic(struct net_device *netdev, void *hndl)
{
	struct pci_dev *pcidev = hndl;

	if (vbus == NULL)
		return;
	//if (!boot_flag) {
		sysfs_remove_link(&netdev->dev.kobj, "device");
		dev_put(netdev);
	//}
	pci_remove_bus_device(pcidev);
	pci_dev_put(pcidev);
}
EXPORT_SYMBOL(xt_vpci_remove_vnic);

void xt_vpci_vdev_remove(struct pci_dev *dev)
{
}

static struct pci_driver xt_vpci_vdev_driver = {
	.name = "Xtreme-Virtual-NIC",
	.id_table = xt_vpci_dev_table,
	.remove = xt_vpci_vdev_remove
};

int xt_vpci_bus_init(void)
{
	int i = 2;

	//if (!xscore_vpci_enable)
	//	return 0;

	sysdata = kzalloc(sizeof(void *), GFP_KERNEL);
	while (i > 0) {
		vbus = pci_scan_bus_parented(NULL, i, &xt_vpci_ops, sysdata);
		if (vbus != NULL)
			break;
		memset(sysdata, 0, sizeof(void *));
		i--;
	}
	if (vbus == NULL) {
		kfree(sysdata);
		return -EINVAL;
	}
	if (pci_register_driver(&xt_vpci_vdev_driver) < 0) {
		pci_remove_bus(vbus);
		vbus = NULL;
		return -EINVAL;
	}
	printk("here");
	xt_vpci_add_vnic("xsvnic",0);
	return 0;
}

void xt_vpci_bus_remove(void)
{
	if (vbus) {
		pci_unregister_driver(&xt_vpci_vdev_driver);
		device_unregister(vbus->bridge);
		pci_remove_bus(vbus);
		kfree(sysdata);
		vbus = NULL;
	}
}


static int __init pci_init(void)
{
	printk( "module loaded");
	xt_vpci_bus_init();
	return 0;
}

static void __exit pci_exit(void)
{
        printk(KERN_ALERT "unregister PCI Device\n");
        //pci_unregister_driver(&pci_driver_ops);
}


module_init(pci_init);
module_exit(pci_exit);
MODULE_LICENSE("GPL");

