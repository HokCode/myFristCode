#include <string>
#include <iostream>
#include <sstream>

#include "staticArray.h"
#include "HeapArray.h"
#include "Array.h"
#include "SmartPoint.h"
#include "dynamicArray.h"

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
	for(int i=0; i < l.length(); i++)
	{
		l.set(i, i * i);
	}
	for(int i=0; i < l.length(); i++)
	{
		cout << l[i] << endl;
	}

	cout << endl;

	staticArray<int, 5> m;
	for(int i=0; i < m.length(); i++)
	{
		m.set(i, i);
	}
	for(int i=0; i < m.length(); i++)
	{
		cout << m[i] << endl;
	}

	char reversed[16];

	cout << ">>>" << sizeof(reversed) << endl;

	// cout << "File:	" << __FILE__;
	// cout << "Line:	" << __LINE__;
	// cout << "Function:	" << __func__ << endl;

}