#include<stdio.h>
#include<string.h>

	
int main(int argc, char *argv[])
{
	
	printf("argc = %d\n",argc);
	
	if(argc != 2)
	{
		printf("enter two or more num please!\n");
		return -1;
	}
	
	if(!strcmp(argv[1], "0"))
	{
		printf("your num is 0 !\n");
	}
	
	if(!strcmp(argv[1], "1"))
	{
		printf("your num is 1 !\n");
	}

	
	return 0;
}
















