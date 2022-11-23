#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

int count = 1;
module_param (count, int, 0644); // 3rd parameter is a permission field (octal)
// 	if permission field != 0; the parameter can be modified at location: 
// 	/sys/module/<module_name>/parameters/<parameter_name>


bool check = false;
module_param (check, bool, 0644);


static int __init ex04_module_init (void)
{
	int index;

	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	for (index = 0; index < count; index++)
	{
		printk (KERN_INFO "Hello World: idx = %d\n", index);
	}
	if (check)
		pr_warn ("Check is set to true!\n");


	return 0;
}

static void __exit ex04_module_exit (void)
{
	int index;

	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	for (index = 0; index < count; index++)
	{
		printk (KERN_INFO "Goodbye World: idx = %d\n", index);
	}
	if (check)
	{
		pr_info ("Check is true!\n");
	}
}

module_init (ex04_module_init);
module_exit (ex04_module_exit);

