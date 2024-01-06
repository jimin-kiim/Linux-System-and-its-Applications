#include "../calclock.h"
#include "../linked_list_impl.h"
#include <linux/list.h>
#include <linux/spinlock.h>

spinlock_t my_lock;
DEFINE_SPINLOCK(my_lock);

LIST_HEAD(my_list);

unsigned long long count_insert, count_search, count_delete;
unsigned long long time_insert, time_search, time_delete;

void *add_to_list(int thread_id, int range_bound[]) {
	struct timespec localclock[2];
	struct my_node *first = NULL;

	int i;
	for (i = range_bound[0]; i <= range_bound[1]; i++) {
		struct my_node *new = kmalloc(sizeof(struct my_node), GFP_KERNEL);
		new->data = i;

		spin_lock(&my_lock);
		getrawmonotonic(&localclock[0]);

		list_add(&new->list, &my_list);

		getrawmonotonic(&localclock[1]);

		calclock(localclock, &time_insert, &count_insert);
		spin_unlock(&my_lock);
		if (first == NULL) first = new;
	}

	printk(KERN_INFO "thread #%d range: %d ~ %d\n", thread_id, range_bound[0], range_bound[1]);
	return first;
}

int search_list(int thread_id, void *data, int range_bound[]) {
	struct timespec localclock[2];
	struct my_node *cur = (struct my_node *) data, *tmp;
	spin_lock(&my_lock);

	list_for_each_entry_safe(cur, tmp, &my_list, list) {
		getrawmonotonic(&localclock[0]);
		getrawmonotonic(&localclock[1]);
		calclock(localclock, &time_search,&count_search);
	};
	spin_unlock(&my_lock);
	return 0;
}

int delete_from_list(int thread_id, int range_bound[]) {
	struct my_node *cur, *tmp;
	struct timespec localclock[2];
	spin_lock(&my_lock);

	list_for_each_entry_safe(cur, tmp, &my_list, list) {
		getrawmonotonic(&localclock[0]);
		list_del(&cur->list);
		kfree(cur);
		getrawmonotonic(&localclock[1]);
		calclock(localclock, &time_delete, &count_delete);

	};
	spin_unlock(&my_lock);
	return 0;
}



