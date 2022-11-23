#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int ex03_module_function (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}

EXPORT_SYMBOL (ex03_module_function);


static int __init ex03_module_init (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}

static void __exit ex03_module_exit (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
}

module_init (ex03_module_init);
module_exit (ex03_module_exit);

