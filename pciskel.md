#Sample pci-skel.c driver

#include <linux/kernel.h>

#include <linux/module.h>

#include <linux/pci.h>

#include <linux/init.h>



static struct pci\_device\_id ids[.md](.md) = {

> { PCI\_DEVICE(0x8086, 0x100E), }

> { PCI\_DEVICE(PCI\_VENDOR\_ID\_INTEL, CI\_DEVICE\_ID\_INTEL\_82801AA\_3), },

> { 0, }
};

MODULE\_DEVICE\_TABLE(pci, ids);

static unsigned char skel\_get\_revision(struct pci\_dev **dev)
{
> u8 revision;**

> pci\_read\_config\_byte(dev, PCI\_REVISION\_ID, &revision);
> return revision;
}

static int probe(struct pci\_dev **dev, const struct pci\_device\_id**id)
{
> int result;

> /**Do probing type**/

> if ((result = pci\_enable\_device(dev)) < 0) {
> > return result;

> }
> if (skel\_get\_revision(dev) == 0x42)
> > return -ENODEV;

> return 0;
}

static void remove(struct pci\_dev **dev)
{
> /** clean up any allocated resources and stuff here. **/**

> /**like call release\_region();**/
}

static struct pci\_driver pci\_driver = {
> .name = "pci\_skel",
> .id\_table = ids,
> .probe = probe,
> .remove = remove,
};

static int init pci\_skel\_init(void)
{
> return pci\_register\_driver(&pci\_driver);
}

static void exit pci\_skel\_exit(void)
{
> pci\_unregister\_driver(&pci\_driver);
}

MODULE\_LICENSE("GPL");

module\_init(pci\_skel\_init);
module\_exit(pci\_skel\_exit);