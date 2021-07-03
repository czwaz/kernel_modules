#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");

int count = 1;
module_param (count, int, 0644); // 3rd parameter is a permission field (octal)
// 	if permission field != 0; the parameter can be modified at location: 
// 	/sys/module/<module_name>/parameters/<parameter_name>

int ex04_module_init (void)
{
	int index;

	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	for (index = 0; index < count; index++)
	{
		printk (KERN_INFO "Hello World: idx = %d\n", index);
	}

	return 0;
}

void ex04_module_exit (void)
{
	int index;

	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	for (index = 0; index < count; index++)
	{
		printk (KERN_INFO "Goodbye World: idx = %d\n", index);
	}
}

module_init (ex04_module_init);
module_exit (ex04_module_exit);

