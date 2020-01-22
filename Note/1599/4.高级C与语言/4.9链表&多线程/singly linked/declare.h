struct linked
{
	int num;
	char name[10];
	struct linked *pNext;
};

struct linked *creat(void);

void check_linked(struct linked *head);

void headadd_linked(struct linked *head, struct linked *new);

void add_linked(struct linked *head, struct linked *new);

void insert_linked(struct linked *head, struct linked *new);

void ergodic_linked(struct linked *head);	//遍历链表。

int delete_linked(struct linked *head);

void reverse_linked(struct linked *head);		//逆序节点。