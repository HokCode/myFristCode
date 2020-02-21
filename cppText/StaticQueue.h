#ifndef _STATICQUEUE_H_
#define _STATICQUEUE_H_

#include "Queue.h"

template
< typename T, int N >
class StaticQueue : public Queue<T>
{
protected:
	int m_space[N];
	int m_front;
	int m_rear;
	int m_length;
public:
	StaticQueue()
	{
		m_front = 0;
		m_rear = 0;
		m_length = 0;
	}

	int length()
	{
		return m_length;
	}

	void add(const T& e)
	{
		if( m_length < N )
		{
			m_space[m_rear] = e;
			m_rear = (m_rear + 1) % N;	//循环计数法
			m_length++;
		}
		else
		{

		}
	}

	void remove()
	{
		if(m_length > 0)
		{
			m_front = (m_front + 1) % N;	//循环计数法
			m_length--;
		}
		else
		{

		}
	}

	T front() const
	{
		if(m_length > 0)
		{
			return m_space[m_front];
		}
		else
		{

		}
	}

	void clear()
	{
		m_front = 0;
		m_rear = 0;
		m_length = 0;
	}

	int capacity() const
	{
		return N;
	}

	~StaticQueue()
	{

	}
	
};

















#endif