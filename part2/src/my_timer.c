#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("COP4610");
MODULE_DESCRIPTION("my_timer kernel module");

static struct proc_dir_entry *proc_entry;

static ssize_t timer_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos) {
    /* TODO: implement timer read */
    return 0;
}

static const struct proc_ops timer_fops = {
    .proc_read = timer_read,
};

static int __init timer_init(void) {
    proc_entry = proc_create("timer", 0644, NULL, &timer_fops);
    if (!proc_entry)
        return -ENOMEM;
    return 0;
}

static void __exit timer_exit(void) {
    proc_remove(proc_entry);
}

module_init(timer_init);
module_exit(timer_exit);
