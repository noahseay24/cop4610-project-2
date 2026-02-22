#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/list.h>
#include <linux/mutex.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("COP4610");
MODULE_DESCRIPTION("Elevator kernel module");

static struct proc_dir_entry *proc_entry;

static ssize_t elevator_read(struct file *file, char __user *ubuf, size_t count, loff_t *ppos) {
    /* TODO: implement elevator status read */
    return 0;
}

static const struct proc_ops elevator_fops = {
    .proc_read = elevator_read,
};

static int __init elevator_init(void) {
    proc_entry = proc_create("elevator", 0644, NULL, &elevator_fops);
    if (!proc_entry)
        return -ENOMEM;
    return 0;
}

static void __exit elevator_exit(void) {
    proc_remove(proc_entry);
}

module_init(elevator_init);
module_exit(elevator_exit);
