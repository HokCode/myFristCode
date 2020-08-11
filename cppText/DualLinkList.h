#ifndef _DUALLINKLIST_H_
#define _DUALLINKLIST_H_

#include "List.h"


//双向链表
template
<typename T>
class DualLinkList : public List<T>
{
protected:
	struct Node
	{
		T value;
		Node* next;
		Node* pre;
	};
	mutable struct 
	{
		char reversed[sizeof(T)];
		Node* next;
		Node* pre;
	}m_head;
	int m_length;

	Node* m_current;
	int m_step;

public:
	DualLinkList()
	{
		m_head.next = NULL;
		m_head.pre = NULL;
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
		Node* next = current->next;

		if( ret && current )
		{
			Node* newNode = create();
			if ( newNode != NULL)
			{
				newNode->value = e;

				newNode->next = current->next;
				current->next = newNode;

				if( current == reinterpret_cast<Node*>(&m_head) )
				{
					newNode->pre = NULL;
				}
				else
				{
					newNode->pre = current;
				}

				if( next != NULL )
				{
					next->pre = newNode;
				}
				
				m_length++;
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

		if( ret )
		{
			Node* current = position(i);
			Node* toDel = current->next;
			Node* next = toDel->next;

			current->next = next;

			if( next != NULL )
			{
				next->pre = toDel->pre;
			}

			if( this->m_current == toDel )
			{
				this->m_current = next;
			}

			m_length--;
			destroy(toDel);
		}
		else
		{
			
		}

		return ret;
	}

	bool set(int i, const T& e)
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

	T get(int i) const
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

	bool get(int i, T& e) const
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

	void clear()
	{
		while( m_length > 0 )
		{
			remove(0);
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

	bool move(int i, int step = 1)	//移动游标m_current，传入m_step值。i开始移动，每次移动step步
	{
		bool ret = ((0 <= i) && (i < this->m_length));
		if( ret )
		{
			this->m_current = position(i)->next;
			this->m_step = step;
		}

		return ret;
		
	}

	bool end()					//判断游标是否是最后一个
	{
		return ( this->m_current == NULL );
	}

	T current()					//返回游标的value
	{
		if ( this->m_current )
		{
			return this->m_current->value;
		}
		else
		{

		}
	}

	bool next()					//游标向后移动m_step步
	{
		int oneStep = 0;
		while((oneStep < this->m_step) && (!end()))
		{
			this->m_current = this->m_current->next;
			oneStep++;
		}

		return ( oneStep == this->m_step );
	}

	bool pre()					//游标向前移动m_step步
	{
		int oneStep = 0;
		while((oneStep < this->m_step) && (!end()))
		{
			this->m_current = this->m_current->pre;
			oneStep++;
		}

		return ( oneStep == this->m_step );
	}


	~DualLinkList()
	{
		clear();
	}
};




























#endif