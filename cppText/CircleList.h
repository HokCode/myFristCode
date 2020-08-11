#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

#include "LinkList.h"

//循环单向链表
template
<typename T>
class CircleList : public LinkList<T>
{
protected:
	typedef typename LinkList<T>::Node Node;
	Node* last()
	{
		return this->position(this->m_length-1)->next;
	}

	void last_to_first()
	{
		last()->next = this->m_head.next;
	}

	int mod(int i) const	//i取余
	{
		return (this->m_length == 0) ? 0 : i % (this->m_length);
	}

public:
	bool insert(const T& e)
	{
		return this->insert(this->m_length, e);
	}

	bool insert(int i, const T& e)
	{
		bool ret = false;

		i = i % (this->m_length + 1);

		ret = LinkList<T>::insert(i, e);

		if( ret && (i == 0) )
		{
			last_to_first();
		}

		return ret;
	}

	bool remove(int i)
	{
		bool ret = true;

		i = mod(i);

		// ret = LinkList<T>::remove(i);
		//没有直接调用父类函数。防止销毁时抛出异常

		if( i == 0 )
		{
			Node* toDel = this->m_head.next;

			if( toDel != NULL )
			{
				this->m_head.next = toDel->next;
				this->m_length--;
				if ( this->m_length > 0)
				{
					last_to_first();

					if( this->m_current == toDel )
					{
						this->m_current = toDel->next;
					}

				}
				else
				{
					this->m_head.next = NULL;
					this->m_current = NULL;
				}

				this->destroy(toDel);
				//所有工作做完才销毁节点。
			}
			else
			{
				ret = false;
			}
		}
		else
		{
			ret = LinkList<T>::remove(i);
		}

		return ret;
	}

	bool set(int i, const T& e)
	{
		return LinkList<T>::set(mod(i));
	}

	T get(int i) const
	{
		return LinkList<T>::get(mod(i));
	}

	bool get(int i, T& e) const
	{
		return LinkList<T>::get(mod(i), e);
	}

	void clear()
	{
		while( this->m_length > 1 )
		{
			remove(1);
		}

		if(this->m_length == 1)
		{
			remove(0);
		}
	}

	int find(const T& e)
	{
		int ret = -1;
		Node* findNode = this->m_head.next;

		for(int i=0; i<this->m_length; i++)
		{
			if( findNode->value == e )
			{
				ret = i;
				break;
			}

			findNode = findNode->next;
		}

		return ret;
	}

	bool move(int i, int step = 0)
	{
		return LinkList<T>::move(mod(i), step);
	}

	bool end()
	{
		return (this->m_length == 0) || (this->m_current == NULL);
	}

	bool next()
	{
		return LinkList<T>::next();
	}

	~CircleList()
	{
		clear();
	}

};




























#endif