#ifndef _DUALCIRCLELIST_H_
#define _DUALCIRCLELIST_H_

#include "LinuxList.h"
#include "DualLinkList.h"

template
<typename T>
class DualCircleList : public DualLinkList<T>
{
protected:
	struct Node
	{
		list_head head;
		T value;
	};

	int mod(int i) const
	{
		return (this->m_length == 0) ? 0 : i % (this->m_length);
	}
	
	list_head m_head;
	list_head* m_current;

public:
	DualCircleList()
	{
		INIT_LIST_HEAD(&m_head);

		this->m_step = 1;
		this->m_current = NULL;
		this->m_length = 0;
	}

	list_head* position(int i) const
	{
		i = mod(i);
		list_head* ret = const_cast<list_head*>(&m_head);
		for(int p=0; p<i; p++)
		{
			ret = ret->next;
		}

		return ret;
	}

	bool insert(const T& e)
	{
		return this->insert(this->m_length, e);
	}

	bool insert(int i, const T& e)
	{
		bool ret = true;
		Node* newNode = new Node();

		i = i % (this->m_length + 1);

		if( newNode != NULL )
		{
			newNode->value = e;
			list_add_tail(&newNode->head, position(i)->next);

			this->m_length++;
		}
		else
		{
			cout << "no enough memory..." << endl;
		}

		return ret;
	}

	bool remove(int i)
	{
		i = mod(i);
		bool ret = (0 <= i) && (i < this->m_length);

		if( ret )
		{
			Node* toDel = list_entry(position(i)->next, Node, head);
			list_del(position(i)->next);

			if( this->m_current == position(i)->next )
			{
				this->m_current = this->m_current->next;
			}

			this->m_length--;

			delete(toDel);
		}
		else
		{

		}

		return ret;
	}

	bool set(int i, const T& e)
	{
		i = mod(i);
		bool ret = (0 <= i) && (i < this->m_length);
		if( ret )
		{
			Node* node = list_entry(position(i)->next, Node, head);
			node->value = e;
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
		i = mod(i);
		bool ret = (0 <= i) && (i < this->m_length);
		if( ret )
		{
			Node* node = list_entry(position(i)->next, Node, head);
			e = node->value;
		}

		return ret;
	}

	void clear()
	{
		while( this->m_length > 0 )
		{
			remove(0);
		}

		// this->m_length = 0;
		// this->m_current = NULL;
	}

	int find(const T& e)
	{
		int ret = -1;
		int i = 0;
		list_head* current = NULL;
		list_for_each(current, &m_head)
		{
			if(list_entry(current, Node, head)->value == e)
			{
				ret = i;
				break;
			}

			i++;
		}

		return ret;
	}

	bool move(int i, int step = 1)
	{
		bool ret = (step > 0);
		i = mod(i);
		ret = ret && ((0 <= i) && (i < this->m_length));
		if( ret )
		{
			this->m_current = position(i)->next;
			this->m_step = step;
		}

		return ret;
	}

	bool end()
	{
		return (this->m_length == 0);
	}

	bool next()
	{
		int i = 0;
		while( i < this->m_step )
		{
			if(this->m_current != &m_head)
			{
				this->m_current = this->m_current->next;
				i++;
			}
			else
			{
				this->m_current = this->m_current->next;
				//跳过头结点不算次数。
			}
		}

		if( this->m_current == &m_head )
		{
			this->m_current = this->m_current->next;
		}

		return (i == this->m_step);
	}

	bool pre()
	{
		int i = 0;
		while( i < this->m_step )
		{
			if(this->m_current != &m_head)
			{
				this->m_current = this->m_current->prev;
				i++;
			}
			else
			{
				this->m_current = this->m_current->prev;
				//跳过头结点不算次数。
			}
		}

		if( this->m_current == &m_head )
		{
			this->m_current = this->m_current->prev;
		}

		return (i == this->m_step);
	}

	T current()
	{
		return list_entry(this->m_current, Node, head)->value;
	}

	~DualCircleList()
	{
		clear();

	}

};





#endif



