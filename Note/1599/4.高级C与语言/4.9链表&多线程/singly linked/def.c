#include<stdio.h>
#include<stdlib.h>
#include"declare.h"


#define LEN sizeof(struct linked)


/*--------------------------------------
|										|
|				创建链表			    |	
|										|	
 --------------------------------------*/
struct linked *creat(void)
{
	struct linked *p1 = NULL;	
	p1 = (struct linked *)malloc(LEN);
	
	printf("enter your message please.get num to 0 to end\n");
	
	printf("num:");scanf("%d",&(p1->num));
	printf("name:");scanf("%s",p1->name);
	
	p1->pNext = NULL;
	
	return(p1);
}


/*--------------------------------------
|										|
|			头部增加节点			    |	
|										|	
 --------------------------------------*/
 void headadd_linked(struct linked *head, struct linked *new)
 {
	 struct linked *p = NULL;
	 p = head;
	 
	 if(NULL != p->pNext)
	 {
		new->pNext = p->pNext;
		p->pNext = new; 
	 }
	 
	 
	 else
	 {
		 new->pNext = NULL;
		 p->pNext = new;
	 }
 
 }
 

/*--------------------------------------
|										|
|			尾部增加节点			    |	
|										|	
 --------------------------------------*/
void add_linked(struct linked *head, struct linked *new)
{
	int count = 0;
	struct linked *p = NULL;
	p = head;
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		count++;
	}
		
	if(new->num != 0)
	{	
		p->pNext = new;
		head->num = count + 1;
	}
}


/*--------------------------------------
|										|
|		 任意位置插入链表节点			|	
|										|	
 --------------------------------------*/
void insert_linked(struct linked *head, struct linked *new)
{
	int i = 0, a = 0;
	struct linked *p1 = NULL;
	p1 = head;
	
	printf("send the num of you want to insert the linker please.\n");
	scanf("%d",&a);
	
		
	for(i = 0; i < (a-1); i++)
	{
		p1 = p1->pNext;
	}
	
	new->pNext = p1->pNext;	//新节点指向原本的第a节点。
	p1->pNext = new;		//原本的第(a-1)个节点指向新节点。
	
	head->num += 1;
}


/*--------------------------------------
|										|
|			 查看链表节点				|	
|										|	
 --------------------------------------*/
void check_linked(struct linked *head)
{
	int i = 0, a = 0;
	struct linked *p = NULL;
	
	printf("send the num of the people you want to check please.\n");
	scanf("%d",&a);
	
	p = head;
	
	for(i = 0;i < a;i++)
	{
		p = p->pNext;
		
		if(NULL == p->pNext)
			break;
	}
	
	if(i < a-1)
	{
		printf("your num is wrong!\n");
	}

	else
		printf("the message is :num : %d ,name : %s\n",p->num,p->name);
		
}	


/*--------------------------------------
|										|
|				遍历链表			    |	
|										|	
 --------------------------------------*/
void ergodic_linked(struct linked *head)
{
	struct linked *p;
	p = head;
	
	printf("--------ergodic begin----------\n");
	
	while(NULL != p->pNext)
	{
		p = p->pNext;
		printf("num = %d, name = %s.\n",p->num, p->name);
	}
	
	printf("--------ergodic done-----------\n");
	
}


/*--------------------------------------
|										|
|				删除节点			    |	
|										|	
 --------------------------------------*/

int delete_linked(struct linked *head)
{
	
	int i = 0, a = 0;
	struct linked *p = NULL;
	
	printf("send the num of the people you want to delete please.\n");
	scanf("%d",&a);
	
	p = head;

	if(a > head->num)
	{
		printf("your num is wrong!delete error.\n");
		return -1;
	}
	
	for(i = 0;i < (a-1);i++)
	{
		p = p->pNext;				
	}
	
	if(NULL != p->pNext->pNext)
	{
		struct linked *p1 = NULL;
		p1 = p->pNext->pNext;
		free(p->pNext);
		p->pNext = p1;
		
		head->num--;
		
		printf("delete successfully.\n");
		
		return 0;
	}

	if(NULL == p->pNext->pNext)
	{
		free(p->pNext);
		p->pNext = NULL;
		
		head->num--;
		
		printf("delete successfully.\n");
		
		return 0;
	}
	

}


/*--------------------------------------
|										|
|				链表逆序			    |	
|										|	
 --------------------------------------*/

void reverse_linked(struct linked *head)
{
	struct linked *p1,*p2;
	
	p1 = head->pNext;
	p2 = p1->pNext;
	
	if((NULL == head->pNext) && (NULL == p2->pNext))
		return;
	
	while(NULL != p1->pNext)
	{
		

		
	
		if(head->pNext == p1)
		{
			p1->pNext = NULL;
		}
		
		else
		{		
			p1->pNext = head->pNext;
			head->pNext = p1;
		}
		
		p1 = p2;
		p2 = p2->pNext;				
	}
		headadd_linked(head, p1);
	
	
	
	/*
	struct linked *p = head->pNext;	
	struct linked *pBack;				
	if ((NULL == p) || (NULL == p->pNext))
		return;
	
	while (NULL != p->pNext)	
	{
		
		pBack = p->pNext;			//用pBack保留p的下一个节点。
		if (p == head->pNext)
		{			
			p->pNext = NULL;	//原链表的下一个指针要作为新链表的尾节点，所以指向NULL。
		}
		else
		{			
			p->pNext = head->pNext;
		}
		head->pNext = p;		
		p = pBack;		
	}
	headadd_linked(head, p);
	*/
}
















































