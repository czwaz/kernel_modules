#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

__init void ex02_function1 (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
}

void ex02_function2 (void)
{
	printk (KERN_INFO "Inside the %s fucntion\n", __FUNCTION__);
}

__initdata int count = 5; // __initdata frees memory of this variable after init function has run

__init int ex02_module_init (void) // __init frees up the memory needed for this function after the module is initialized
{
	int index = 0;
	
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	for (index = 0; index < count; index++)
	{
		printk (KERN_INFO "Index = %d\n", index);
	}

	ex02_function1 ();
	ex02_function2 ();

	return 0;
}

void ex02_module_exit (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);

	ex02_function2 ();
}

module_init (ex02_module_init);
module_exit (ex02_module_exit);
