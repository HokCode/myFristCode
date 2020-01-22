#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"declare.h"

	
	
int main(int argc, char *argv[])
{
	int inum = 0;
	struct linked *phead = NULL, *pNhead = NULL;
	struct linked *pt;
	
	phead = (struct linked *)malloc(sizeof(struct linked));
	phead->num = 0;
	
	do
	{
		pt = creat();
		add_linked(phead, pt);		
		
	}while(  pt->num != 0 );
	
	
	
	
	reverse_linked(phead);
	
		
	//headadd_linked(phead,pt);

	ergodic_linked(phead);


/*	
	while(inum != 5)
	{
		printf("enter the server you want to please.\n");
		printf("1.add\n");
		printf("2.delete\n");
		printf("3.check\n");
		printf("4.read all person's message\n");
		printf("5.exit\n");
		
		scanf("%d",&inum);
		
		switch(inum)
		{
			case 1:add_linked(phead, creat());;break;
			case 2:delete_linked(phead);break;
			case 3:check_linked(phead);break;
			case 4:ergodic_linked(phead);break;
			case 5:inum = 5;break;
			default:printf("num error!\n");
		}
	}
	
	*/
	
	//printf("number of people: %d\n",phead->num);	
					

;

	
	return 0;
}
















