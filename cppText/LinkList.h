#ifndef _LINKLIST_H_
#define	_LINKLIST_H_

#include <iostream>
#include "List.h"

template < typename T >
class LinkList : public List<T>
{
protected:
	struct Node
	{
		T value;
		Node* next;
	};
	mutable struct 
	{
		char reversed[sizeof(T)];
		Node* next;
	}m_head;
	int m_length;

	Node* m_current;
	int m_step;

public:
	LinkList()
	{
		m_head.next = NULL;
		m_length = 0;
		m_step = 1;
		m_current = NULL;
	}

	virtual bool insert(const T& e)
	{
		return insert(m_length, e);
	}

	virtual bool insert(int i, const T& e)
	{
		bool ret = (0 <= i) && (i <= m_length);
		Node* current = position(i);

		if( ret && current )
		{
			Node* newNode = create();
			if ( newNode != NULL)
			{
				newNode->value = e;
				newNode->next = current->next;
				current->next = newNode;

				m_length++;
				ret = true;
			}
			
		}
		else
		{

		}

		return ret;
	}

	virtual bool remove(int i)
	{
		bool ret = (0 <= i) && (i < m_length);
		Node* node = position(i);

		if( ret && node )
		{
			Node* toDel = node->next;
			node->next = toDel->next;			

			if( this->m_current == toDel )
			{
				this->m_current = toDel->next;
			}

			m_length--;
			destroy(toDel);
		}
		else
		{

		}

		return ret;
	}

	virtual bool set(int i, const T& e)
	{
		bool ret = (0 <= i) && (i < m_length);
		Node* node = position(i);

		if( ret && node )
		{
			node->next->value = e;
		}
		else
		{

		}

		return ret;
	}

	virtual T get(int i) const
	{
		T tmp;
		if( this->get(i, tmp) )
		{
			return tmp;
		}
		else
		{
			
		}
	}

	virtual bool get(int i, T& e) const
	{
		bool ret = (0 <= i) && (i < m_length);
		Node* node = position(i);

		if( node && ret )
		{
			e = node->next->value;
		}
		else
		{

		}

		return ret;
	}

	Node* create()
	{
		Node* newNode = new Node;
		return newNode;
	}

	void destroy(Node* pn)
	{
		delete pn;
	}

	int length() const
	{
		return m_length;
	}

	virtual void clear()
	{
		while( m_head.next )
		{
			Node* tmp = m_head.next;
			m_head.next = tmp->next;
			destroy(tmp);
		}

		m_length = 0;
	}

	Node* position(int step) const		//返回的是目标位置前一位
	{
		Node* current = reinterpret_cast<Node*>(&m_head);
		for(int i=0; i<step; i++)
		{
			current = current->next;
		}

		return current;
	}

	virtual bool move(int i, int step = 1)	//移动游标m_current，传入m_step值。i开始移动，每次移动step步
	{
		bool ret = ((0 <= i) && (i < this->m_length));
		if( ret )
		{
			this->m_current = position(i)->next;
			this->m_step = step;
		}

		return ret;
		
	}

	virtual bool end()					//判断游标是否是最后一个
	{
		return ( this->m_current == NULL );
	}

	virtual T current()					//返回游标的value
	{
		if ( this->m_current )
		{
			return this->m_current->value;
		}
		else
		{
			
		}
	}

	virtual bool next()					//游标向后移动m_step步
	{
		int oneStep = 0;
		while((oneStep < this->m_step) && (!end()))
		{
			this->m_current = this->m_current->next;
			oneStep++;
		}

		return (oneStep == this->m_step);
	}

	virtual int find(T value)
	{
		int ret = -1;
		Node* current = m_head.next;

		for(int i=0; i<m_length; i++)
		{
			if(current->value == value)
			{
				ret = i;
				break;
			}

			current = current->next;
		}

		return ret;
	}

	~LinkList()
	{
		clear();
	}
};
















#endif