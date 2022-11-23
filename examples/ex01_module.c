#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init ex01_module_init (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}

static void __exit ex01_module_exit (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
}

module_init (ex01_module_init);
module_exit (ex01_module_exit);

