#include<stdio.h>
#include<math.h>
#include"fomula.h"

int change_int(char *pnum)	
{	
	char *p = pnum;
	int j = 0, count = 0, num = 0, b = 0;		

	while(*p != '\0')
	{
		p++;
		count++;
	}
		
	p--;count--;
	
	for(j=0;j <= count;j++)
	{
		num += ((int)*p - 48)*(pow(10,j));
		p--;
	}
			
	return num;
}
	
double add(double a, double b)
{
	return a+b;
}

double sub(double a, double b)
{
	return a-b;
}

double mul(double a, double b)
{
	return a*b;
}

double div(double a, double b)
{
	return a/b;
}




























































