/*
 * 	文件名： dog.s
 * 	作者：   HGJ
 *
 *  裸机程序
 */

#define WTCON 		0xE2700000
#define GPJ0CON 	0xE0200240
#define GPJ0DAT		0xE0200244
#define SVC_STACK	0xD0037D80
 
.global _start
_start:	
	
	//关看门狗
	ldr r0, =WTCON
	ldr r1, =~(1<<5)		
	str r1, [r0]			
	
	//设置svc栈
	ldr sp, =SVC_STACK
	
	//开启 or 关闭icache
	mrc p15, 0, r0, c1, c0, 0;		//读取cp15中的c1到r0中
	bic r0, r0, #(1<<12)			//bit12 置0 关闭icache
	orr r0, r0, #(1<<12)			//bit12 置1 开启icache
	mcr p15, 0, r1, c1, c0, 0;
	
	//这里开始可以调用C程序
	bl cfuntion
	

flag:						
	b flag					
	

































































































