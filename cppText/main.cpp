#include <string>
#include <iostream>
#include <sstream>

#include "staticArray.h"
#include "HeapArray.h"
#include "Array.h"
#include "SmartPoint.h"
#include "dynamicArray.h"
#include "LinkList.h"
#include "Exception.h"
#include "SharePoint.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "LinuxList.h"
#include "DualCircleList.h"

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
	Test()
	{
		cout << "Test()" << endl;
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

void func()
{
	CircleList<int> l;

	for(int i=1; i<=41; i++)
	{
		l.insert(i);
	}

	l.move(0, 2);

	while(l.length())
	{
		l.next();
		cout << l.current() << endl;
		//cout << l.find(l.current()) << endl;
		l.remove(l.find(l.current()));
	}

	cout << "len: " << l.length() << endl;
}



int main()
{
	struct Node
	{
		list_head head;
		int value;
	};

	Node node;
	list_head* pt = &node.head;

	Node* pt1 = reinterpret_cast<Node*>(pt);
	Node* pt2 = list_entry(pt, Node, head);

	cout << pt1 << endl;
	cout << pt2 << endl;

	// cout << "File:	" << __FILE__;
	// cout << "Line:	" << __LINE__;
	// cout << "Function:	" << __func__ << endl;

}