#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>

MODULE_AUTHOR("Shebetin Bogdan IV-83");
MODULE_DESCRIPTION("Darova Lab5");
MODULE_LICENSE("Dual BSD/GPL");

static int amount = 1;
module_param(amount, uint, S_IRUGO);
MODULE_PARM_DESC(times, "Number of outputting Darova");

static int __init hello_init(void)
{
  uint i = 0;

  if(amount == 0)
  {
    printk(KERN_WARNING "Value equals 0");
  } 
  else if(amount >= 5 && amount <= 10) 
  {
    printk(KERN_WARNING "Value between 5 and 10");
  } 
  else if(amount > 10)
  {
    printk(KERN_ERR "Value is bigger than 10");
    return -EINVAL;
  }

  for(i=0; i<amount; i++)
  {
    printk(KERN_EMERG "Darova\n");
  }

  printk(KERN_INFO "Number: %d\n", amount);

  return 0;
}

static void __exit hello_exit(void)
{
  /* Do nothing */
}

module_init(hello_init);
module_exit(hello_exit);
