#ifndef _LINKSTACK_H_
#define	_LINKSTACK_H_

#include "Stack.h"
#include "LinkList.h"

template
< typename T >
class LinkStack : public LinkList<T>
{
protected:
	LinkList<T> Stack;
	
public:
	void push(const T& e)
	{
		Stack.insert(0, e);
	}

	void pop()
	{
		if( Stack.length() > 0 )
		{
			Stack.remove(0);
		}
		else
		{

		}
	}

	T top() const
	{
		if( Stack.length() > 0 )
		{
			Stack.get(0);
		}
		else
		{
			
		}
	}

	int size() const
	{
		return Stack.length();
	}

	void clear()
	{
		Stack.clear();
	}
};

/*
应用：编译器检查符号配对
bool is_left(char c)
{
	return (c == '(') || (c == '{') || (c == '[') || (c == '<');
}

bool is_right(char c)
{
	return (c == ')') || (c == '}') || (c == ']') || (c == '>');
}

bool is_quo(char c)
{
	return (c == '\'') || (c == '\"');
}

bool is_match(char i, char j)
{
	return ((i == '(') && (j == ')')) || 
		   ((i == '{') && (j == '}')) || 
		   ((i == '[') && (j == ']')) || 
		   ((i == '<') && (j == '>')) ||
		   ((i == '\'') && (j == '\'')) ||
		   ((i == '\"') && (j == '\"'));
}

bool scan(const char* code)
{
	bool ret = true;
	LinkStack<char> l;
	code = (code == NULL) ? "" : code;
	int i = 0;

	while( ret && code[i] != '\0' )
	{
		if( is_left(code[i]) )
		{
			l.push(code[i]);
		}
		else if( (is_right(code[i])) )	//不是左，链表栈不为空未必代表出错了。{(< > )},第2个>时栈不为空。
		{
			if( (l.size() != 0) && is_match(l.top(), code[i]) )
			{
				l.pop();
			}
			else
			{
				ret = false;
			}
		}
		else if( is_quo(code[i]) )
		{
			if( is_match(l.top(), code[i]) )
			{
				l.pop();
			}
			else
			{
				l.push(code[i]);
			}
		}
		
		i++;
	}

	return ret && (l.size() == 0);
}
*/








#endif