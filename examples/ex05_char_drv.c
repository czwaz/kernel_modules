#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> /* for character device driver support */

MODULE_LICENSE("GPL");

int ex05_open (struct inode *pinode, struct file *pfile)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t ex05_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}

ssize_t ex05_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return length;
}

int ex05_close (struct inode *pinode, struct file *pfile)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	return 0;
}


/* To hold the file operations performed on this device */
// /lib/modules/$(uname -r)/build/include/linux/fs.h
struct file_operations fops = {
	.owner		= THIS_MODULE,
	.open		= ex05_open,
	.read		= ex05_read,
	.write		= ex05_write,
	.release	= ex05_close,
};

int ex05_module_init (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);
	
	/* register with the kernel and indicate that we are registering a character device driver */
	register_chrdev (269,		// major number
			"My Char Drv",	// name of the driver
			&fops);		// file operations
	
	return 0;
}

void ex05_module_exit (void)
{
	printk (KERN_INFO "Inside the %s function\n", __FUNCTION__);

	/* unregister the character device driver */
	unregister_chrdev (269, "My Char Drv");
}

module_init (ex05_module_init);
module_exit (ex05_module_exit);

