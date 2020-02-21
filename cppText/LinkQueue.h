#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include "Queue.h"
#include "LinuxList.h"
#include "Exception.h"

template
< typename T>
class LinkQueue
{
protected:
	struct Node
	{
		list_head head;
		T value;
	};

	list_head m_head;
	int m_length;

public:
	LinkQueue()
	{
		INIT_LIST_HEAD(&m_head);
		m_length = 0;
	}

	void add(const T& e)
	{
		Node* newNode = new Node();

		if( newNode != NULL )			
		{
			newNode->value = e;
			list_add_tail(&newNode->head, m_head.next);//m_head.next总是队列最后元素

			m_length++;
		}
		else
		{
			THROW_EXCEPTION(Exception, "new no enough memnory");
		}
	}

	void remove()
	{
		if( m_length > 0 )
		{
			list_head* toDel = m_head.prev;	//m_head.prev总是队列最前元素
			list_del(toDel);
			m_length--;

			delete list_entry(toDel, Node, head);
		}
		else
		{

		}
	}

	T front() const
	{
		if( m_length > 0 )
		{
			return list_entry(m_head.prev, Node, head)->value;
		}
		else
		{

		}
	}

	void clear()
	{
		while( m_length > 0 )
		{
			remove();
		}
	}
	
	int length()
	{
		return m_length;
	}

	~LinkQueue()
	{
		clear();
	}

};






















#endif