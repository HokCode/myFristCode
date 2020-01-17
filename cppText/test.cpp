#include <string>
#include <iostream>
#include <sstream>

#include "staticArray.h"
#include "HeapArray.h"
#include "SmartPoint.h"

using namespace std;

template
<int N>
class Sum
{
public:
	static const int Value = Sum<N-1>::Value + N;
};

template
< >
class Sum < 1 >
{
public:
	static const int Value = 1;
};

class Test
{
public:
	Test(const char* name)
	{
		cout << name << "Test()" << endl;
	}
	void print()
	{
		cout << "this is Test()" << endl;
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
};

int main()
{
	staticArray<int, 5> l;
	for(int i=0; i < l.capacity(); i++)
	{
		l.set(i, i * i);
	}
	for(int i=0; i < l.capacity(); i++)
	{
		cout << l[i] << endl;
	}

	cout << "File:	" << __FILE__ << endl;
	cout << "Line:	" << __LINE__ << endl;
	cout << "Function:	" << __func__ << endl;

}