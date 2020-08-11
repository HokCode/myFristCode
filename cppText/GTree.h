#ifndef _GTREE_H_
#define _GTREE_H_

#include "Tree.h"
#include "GTreeNode.h"
#include "LinkList.h"
#include "LinkQueue.h"

#include <iostream>
using namespace std;

template
< typename T >
class GTree : Tree<T>
{
protected:

	LinkQueue<GTreeNode<T>*> m_queue;

	GTreeNode<T>* find(const T& value, GTreeNode<T>* node) const
	{
		GTreeNode<T>* ret = NULL;

		if( node != NULL)
		{			
			if( value == node->value)
			{
				return node;
			}
			else
			{
	
				for(node->child.move(0); !(node->child.end()) && (ret == NULL); node->child.next())
				{
					ret = find(value, node->child.current());
				}

			}
		}

		return ret;
	}

	GTreeNode<T>* find(const GTreeNode<T>* obj, GTreeNode<T>* node) const
	{
		GTreeNode<T>* ret = NULL;

		if( obj == node)
		{
			return node;
		}
		else
		{
			if( node != NULL )
			{
				for(node->child.move(0); !(node->child.end()) && (ret == NULL); node->child.next())
				{
					ret = find(obj, node->child.current());
				}
			}
		}

		return ret;
	}

	void free(GTreeNode<T>* node)
	{
		if( node != NULL )
		{
			for(node->child.move(0); !node->child.end(); node->child.next())
			{
				free(node->child.current());
			}

			if( node->flag() )
			{			
				delete node;
			}
		}
	}

	void remove(GTreeNode<T>* node, GTree<T>*& ret)
	{
		ret = new GTree();

		if( ret == NULL )
		{

		}
		else
		{
			if( node == root() )
			{
				this->m_root = NULL;
			}
			else
			{
				LinkList< GTreeNode<T>* >& child = dynamic_cast<GTreeNode<T>*>(node->parent)->child; //可用引用代替指针
				
				child.remove(child.find(node));	//把node从子结点链表中移除。链表保存的是指向node的指针。

				node->parent = NULL;	//删除后要切断与父结点的联系
			}

			ret->m_root = node;
		}
	
	}

	int count(GTreeNode<T>* node) const
	{
		int ret = 0;

		if( node != 0 )
		{
			for(node->child.move(0); !node->child.end(); node->child.next())
			{
				ret += count(node->child.current());
			}

			ret += 1;
		}

		return ret;
	}

	int height(GTreeNode<T>* node) const
	{
		int ret = 0;

		if( node != NULL )
		{
			for(node->child.move(0); !node->child.end(); node->child.next())
			{
				int h = height(node->child.current());

				if( ret < h )
				{
					ret = h;
				}
			}

			ret += 1;
		}

		return ret;
	}

	int degree(GTreeNode<T>* node) const
	{
		int ret = 0;

		if( node != NULL )
		{
			ret = node->child.length();

			for(node->child.move(0); !node->child.end(); node->child.next())
			{
				int d = degree(node->child.current());

				if( ret < d )
				{
					ret = d;
				}
			}
		}

		return ret;
	}

public:
	GTree() {}

	bool insert(TreeNode<T>* node)
	{
		bool ret = (node != NULL);

		if( ret )
		{
			if( this->m_root == NULL )
			{
				this->m_root = node;
				node->parent = NULL;
			}
			else
			{
				GTreeNode<T>* np = find(node->parent);
				if( np != NULL )
				{
					GTreeNode<T>* n = dynamic_cast<GTreeNode<T>*>(node);
					if( np->child.find(n) < 0)
					{
						np->child.insert(n);
					}
				}
			}
		}

		return ret;
	}

	bool insert(const T& value, TreeNode<T>* parent)
	{
		bool ret = true;

		GTreeNode<T>* node = GTreeNode<T>::NewNode();

		if( node != NULL)
		{
			node->value = value;
			node->parent = parent;
			insert(node);
		}
		else
		{
			ret = false;
		}
		

		return ret;
	}

	SharePoint< Tree<T> > remove(const T& value)
	{
		GTree<T>* ret = NULL;
		GTreeNode<T>* node = find(value);

		if( node != NULL )
		{
			remove(node, ret);
		}
		else
		{

		}

		m_queue.clear();

		return ret;
	}

	SharePoint< Tree<T> > remove(TreeNode<T>* node)
	{
		GTree<T>* ret = NULL;
		node = find(node);

		if( node != NULL )
		{
			remove(dynamic_cast<GTreeNode<T>*>(node), ret);
		}
		else
		{

		}

		m_queue.clear();

		return ret;
	}

	GTreeNode<T>* find(const T& value) const
	{
		GTreeNode<T>* ret = find(value, root());

		return ret;
	}

	GTreeNode<T>* find(TreeNode<T>* node) const
	{
		GTreeNode<T>* ret = find(dynamic_cast<GTreeNode<T>*>(node), root());

		return ret;
	}

	GTreeNode<T>* root() const
	{
		return dynamic_cast<GTreeNode<T>*>(this->m_root);
	}

	int degree() const
	{
		return degree(root());
	}

	int count() const
	{
		return count(root());
	}

	int height() const
	{
		return height(root());
	}

	void clear()
	{
		cout << root() << endl;
		free( root() );
		this->m_root = NULL;

		m_queue.clear();
	}

	bool begin()
	{
		bool ret = ( root() != NULL );
		if( ret )
		{
			m_queue.clear();
			m_queue.add( root() );
		}

		return ret;
	}

	bool end()
	{
		return ( m_queue.length() == 0 );
	}

	bool next()
	{
		bool ret = ( m_queue.length() > 0 );
		if( ret )
		{
			GTreeNode<T>* node = m_queue.front();
			m_queue.remove();

			for(node->child.move(0); !node->child.end(); node->child.next())
			{
				m_queue.add(node->child.current());
			}
		}

		return ret;
	}

	GTreeNode<T>* current()
	{
		return m_queue.front();
	}

	~GTree()
	{
		clear();
	}

};




#endif