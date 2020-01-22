（1）结构定义和初始化

struct list_head {
	struct list_head *next, *prev;
};

//每个链表有一个head，它是一个开始标志，链表的第一个元素是head->next

#define LIST_HEAD_INIT(name) { &(name), &(name) }

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(struct list_head *list) //初始化双向链表为空链表
{
	list->next = list;
	list->prev = list;
}

例如：

struct MyList
{
struct list_head list;
int data;
};

struct MyList mylist1;        //定义一个
INIT_LIST_HEAD(mylist1);  //初始化双向链表为空链表

 

（2）插入操作

void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)   //将new插入到prev和next之间

void list_add(struct list_head *new, struct list_head *head) //将new插入到head链表的首部
void list_add_tail(struct list_head *new, struct list_head *head) //将new插入到head链表的尾部

 

（3）删除操作

__list_del(struct list_head * prev, struct list_head * next) //将prev和next之间的元素删除

void list_del(struct list_head *entry) //在链表中删除元素entry（元素entry脱离链表）

void list_del_init(struct list_head *entry) //在链表中删除元素entry（元素entry脱离链表并初始化为空链表）

（4）替换操作

void list_replace(struct list_head *old, 	struct list_head *new) //将元素new替换old
void list_replace_init(struct list_head *old, struct list_head *new) //将元素new替换old，并将old初始化为空链表。

（5）移动操作

void list_move(struct list_head *list, struct list_head *head) //将list从一个链表中删除，并把它加入到head链表的首部。

void list_move_tail(struct list_head *list, struct list_head *head) //将list从一个链表中删除，并把它加入到head链表的尾部。

void list_cut_position(struct list_head *list,struct list_head *head, struct list_head *entry)//entry是head链表中的元素，list是另一个链表。将entry之前（包含entry）的元素剪切出来入到list中（list链表的首部）。

__list_splice(const struct list_head *list, struct list_head *prev, struct list_head *next) //将链表list加入到另一个链表元素prev和next之间。

void list_splice(const struct list_head *list,struct list_head *head)//将链表list加入到head链表（head链表首部）。

void list_splice_tail(struct list_head *list,struct list_head *head)//将链表list加入到head链表的尾部。

void list_splice_init(struct list_head *list,struct list_head *head) //和list_splice_init功能一样，但初始化list为空.

void list_splice_tail_init(struct list_head *list, struct list_head *head) //和list_splice_tail功能一样，但初始化list为空.

（6）判断

int list_is_last(const struct list_head *list,const struct list_head *head)//判断list是否是head链表的最后一个元素

int list_empty(const struct list_head *head)//判断链表是否为空

int list_empty_careful(const struct list_head *head) //判断链表是否为空，排除另一个CPU在修改它

int list_is_singular(const struct list_head *head)//判断链表是否只有一个元素

(7)宏

list_entry(ptr, type, member) //得到链表所在的结构体（结构体类型为type）。
例：list_entry(&mylist1.list, struct MyList, list)它指向mylist1。

list_for_each(pos, head) //遍历head链表的所有元素，pos是一个游标。
如：//统计链表中元素的个数
struct list_head *p;
int count = 0;
list_for_each(p, mylist1)
{
    ++count;
}

list_for_each_prev(pos, head) //反向遍历head链表的所有元素，pos是一个游标。

list_for_each_safe(pos, n, head) //功能和list_for_each (pos, head)相同，但当内部需要修改pos->next时(例如增加删除元素操作)，使用这个更安全。

list_for_each_prev_safe(pos, n, head) //功能和list_for_each_prev(pos, head)相同，但当内部需要修改pos->prev时(例如增加删除元素操作)，使用这个更安全。

list_for_each_entry(pos, head, member) //遍历所有定义struct list_head所在的结构体实体。
如：在结构struct MyList中定义了struct list_head list，那么要实现打印所有的data成员的数据的代码如下：
struct MyList *p;
list_for_each_entry(p, &mylist1.list, list)
{
    printf(“%d”, p->data);
}

list_for_each_entry_reverse(pos, head, member) //反向遍历所有定义struct list_head所在的结构体实体。

list_for_each_entry_continue(pos, head, member) //从pos位置开始遍历定义struct list_head所在的结构体实体。

list_prepare_entry(pos, head, member)  //如果pos不为空，则返回pos；如果为空，则返回链表头。这个宏用来给list_for_each_entry_continue参数pos初始化。

list_for_each_entry_continue_reverse(pos, head, member) // list_for_each_entry_continue的反向遍历

list_for_each_entry_from(pos, head, member) //从pos元素开始遍历定义struct list_head所在的结构体实体。

//以下安全访问函数，和上面的功能类型。消除修改prev和next带来的影响
list_for_each_entry_safe(pos, n, head, member)
list_for_each_entry_safe_continue (pos, n, head, member)
list_for_each_entry_safe_from(pos, n, head, member)
list_for_each_entry_safe_reverse(pos, n, head, member)