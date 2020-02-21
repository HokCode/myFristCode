#ifndef _STATICSTACK_H_
#define _STATICSTACK_H_

#include "Stack.h"

template
< typename T, int N >
class StaticStack : public Stack<T>
{
protected:
	T m_space[N];
	int m_top;
	int m_size;

public:
	StaticStack()
	{
		m_top = -1;
		m_size = 0;
	}

	void push(const T& e)
	{
		if( m_size < N )
		{
			m_space[m_top + 1] = e;
			m_top++;
			m_size++;
		}
		else
		{

		}
	}

	void pop()
	{
		if(m_size > 0)
		{
			m_top--;
			m_size--;
		}
	}

	T top() const
	{
		if(m_size > 0)
		{
			return m_space[m_top];
		}
	}

	int size() const
	{
		return m_size;
	}

	void clear()
	{
		m_top = -1;
		m_size = 0;
	}
};





















#endif