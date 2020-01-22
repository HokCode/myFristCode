#include<stdio.h>
#include<string.h>
#include"fomula.h"

int main(int argc, char *argv[])
{
	

	double a = 0, b = 0,c = 0;
	
	if(argc<4)
	{
		printf("enter 4 or more param please!\n");
		return -1;
	}
		
	a = change_int(argv[1]);
	b = change_int(argv[3]);
	
	if(!strcmp(argv[2], "+"))
	{
		c = add(a, b);
		printf("the result is %lf\n",c);
	}

	if(!strcmp(argv[2], "-"))
	{
		c = sub(a, b);
		printf("the result is %lf\n",c);
	}
	
	if(!strcmp(argv[2], "x"))
	{
		c = mul(a, b);
		printf("the result is %lf\n",c);
	}
	
	if(!strcmp(argv[2], "/"))
	{
		c = div(a, b);
		printf("the result is %lf\n",c);
	}
	
	return 0;
}















