#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/slab.h>

//链表结构
struct birthday               
{ 
	int day;
	int month;
	int year;
	struct list_head list;
};


//插入元素到链表
static LIST_HEAD(birthday_list);

int simple_init(void)
{
    struct birthday *person;
    int day=1;
    int month=1;
    int year=1000;
    int i=0;
    for(i=0;i<5;i++)
	{
    	    person=kmalloc(sizeof(*person),GFP_KERNEL);
	    person->day=day++;
	    person->month=month++;
	    person->year=year++;
	    INIT_LIST_HEAD(&person->list);
	    list_add_tail(&person->list,&birthday_list);
	}
    
    struct birthday *ptr;
//遍历链表
    list_for_each_entry(ptr,&birthday_list,list)
    {
        /* on each iteration ptr points*/
         /* to the next birthday struct*/
        printk(KERN_INFO "%d-%d-%d\n",ptr->day,ptr->month,ptr->year);
    }

    return 0;

}

//从链表中移除元素

void simple_exit(void)
{
	struct birthday *ptr,*next;
	
	list_for_each_entry_safe(ptr,next,&birthday_list,list)
	{
		/* on each iteration ptr points*/
		/* to the next birthday struct*/
		list_del(&ptr->list);
		kfree(ptr);
	}
	printk(KERN_INFO"Removing Module\n");
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

