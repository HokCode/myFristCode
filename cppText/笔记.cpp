继承相关：
	子类同名变量会覆盖父类同名变量。同名变量访问：
		Child c;
		c.mi = 100;				//子类中的mi
		c.Parent::mi = 1000;	//父类中的mi，作用域分辨符

	子类同名函数也会覆盖父类同名函数，不会重载。同名函数访问：
		Child c;
		c.add();
		c.Parent::add();		//作用域分辨符

	dynamic_cast继承相关的类型转换关键字
		1、相关类中必须有虚函数
		2、
		-指针：
			转换成功：得到目标类型指针
				失败：得到一个空指针
		-引用：
			转换成功：得到目标类型引用
				失败：得到一个异常操作信息

		Parent* p = new child;	//父类指针指向子类对象
		Child* pd = dynamic_cast<Child*>(p);	//转换成功

		Parent* p = new parent;
		Child* pd = dynamic_cast<Child*>(p);	//子类指针不能指向父类。转换失败，得到空指针

	纯虚函数
		1、父类中用virual修饰的函数
		2、用父类指针指向子类对象时，会调用子类的同名函数
			如：析构函数如果不用virtual修饰，那么用父类指针析构子类时，只会调用父类析构函数。子类的析构函数不会被执行。

	构造函数和析构函数中不会发生多态。
	不管是直接和间接调用的虚函数都是当前类实现的函数。			
	子类析构函数直接调用父类的函数。如果父类函数里调用了虚函数，那还是会调用子类版本。
	26-3。

	判定是否需要提供析构函数：
		1、构造函数申请了新资源。
		2、

写法相关：
	typename 与 class：
		如果需要告诉编译器变量是类型不是变量，需要用typename修饰。
		typename可以消除模板中二义性。

		例子：
			typename T::TS * a; //表明TS是类型名，不是变量名。编译器就知道是做定义指针操作，而不是乘法操作。

	mutable
		修饰的成员变量将永远处于可变状态。
		优点：
		缺点：破坏const成员函数特性。

异常相关
	
	c++提供语法用于声明函数所抛出的异常

		void func1()					//可能抛出异常
		void func2() throw(int, char)	//只会抛int、char类型异常
		void func3() throw()			//不抛出异常

	函数抛出的不合规格的异常，全局函数unexpected()被调用。
	如果unexpected()中再次抛异常：
		-异常能够匹配，恢复程序执行
		-否则，调用terminate()结束程序


要点总结：
	1、可能抛出异常的函数最后执行。考虑异常安全性。
	2、指针总要判断是否为NULL。
	3、相同代码尽量封装，增强可读性。
	4、尽量减低代码复杂性。O(n).

linux两个标志性宏:
	//获取member成员内存偏移量
	#define offsetof(type, member) (size_t)&((type*)0->member)
	//size_t：unsigned int类型


	//借助member成员获取type的起始内存地址
	#define container_of(ptr, type, member)	({				\
			const typeof((type*)0->member)* _mptr = ptr;	\
			(type*)((char*)_mptr - offsetof(type, member));	})

	GNU C编译器特有关键字
		1、typeof，获取变量类型
		2、({})，用最后一行代码的运行结果来赋值
























