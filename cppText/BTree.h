#ifndef _BTREE_H_
#define _BTREE_H_

#include "Tree.h"
#include "BTreeNode.h"
#include "LinkQueue.h"
#include "DynamicArray.h"

enum BTNodePos
	{
		ANY,
		LEFT,
		RIGHT
	};

enum BTTraversal
	{
		PreOrder,
		InOrder,
		PostOrder,
		LevelOrder
	};

template
< typename T >
class BTree : public Tree<T>
{
protected:
	LinkQueue<BTreeNode<T>*> m_queue;

	BTreeNode<T>* find(const T& value, BTreeNode<T>* node) const
	{
		BTreeNode<T>* ret = NULL;

		if( node != NULL )
		{
			if( value == node->value )
			{
				ret = node;
			}
			else
			{
				if( ret == NULL )
				{
					ret = find(value, node->left);
				}
				if( ret == NULL )
				{
					ret = find(value, node->right);
				}
			}
		}	

		return ret;
	}

	BTreeNode<T>* find(const BTreeNode<T>* obj, BTreeNode<T>* node) const
	{
		BTreeNode<T>* ret = NULL;

		if( obj == node )
		{
			ret = node;
		}
		else
		{
			if( node != NULL )
			{
				if( ret == NULL )
				{
					ret = find(obj, node->left);
				}
				if( ret == NULL )
				{
					ret = find(obj, node->right);
				}
			}
		}

		return ret;
	}

	bool insert(BTreeNode<T>* n, BTreeNode<T>* np, BTNodePos Pos)
	{
		bool ret = true;

		if( Pos == ANY )
		{
			if( np->left == NULL )
			{
				np->left = n;
			}
			else if( np->right == NULL )
			{
				np->right = n;
			}
			else
			{
				ret = false;
			}
		}
		else if( Pos == LEFT )
		{
			if( np->left == NULL )
			{
				np->left = n;
			}
			else
			{
				ret = false;
			}
		}
		else if( Pos == RIGHT )
		{
			if( np->right == NULL )
			{
				np->right = n;
			}
			else
			{
				ret = false;
			}
		}

		return ret;
	}

	void remove(BTreeNode<T>* node, BTree<T>*& ret)
	{
		ret = new BTree();

		if( ret != NULL )
		{
			if( node == root() )
			{
				this->m_root = NULL;
				node->parent = NULL;
			}
			else
			{
				BTreeNode<T>* np = dynamic_cast<BTreeNode<T>*>(node->parent);

				if( np->left == node )
				{
					np->left = NULL;
				}
				else if( np->right = node )
				{
					np->right = NULL;
				}

				node->parent = NULL;
			}

			ret->m_root = node;
		}
		else
		{
			// throw();
		}

		m_queue.clear();
	}

	void free(BTreeNode<T>* node)
	{
		node = find(node);
		if( node != NULL )
		{
			free(node->left);
			free(node->right);

			if( node->flag() )
			{				
				delete node;
			}
		}
		else
		{
			// throw();
		}
	}

	int count(BTreeNode<T>* node) const
	{
		return ( node != NULL ) ? (count(node->left) + count(node->right) + 1) : 0;
	}

	int degree(BTreeNode<T>* node) const
	{
		int ret = 0;

		if( node != NULL )
		{
			BTreeNode<T>* child[] = {node->left, node->right};
			ret = !!node->left + !!node->right;

			for(int i=0; ( i < 2 ) && ( ret < 2 ); i++)
			{
				int d = degree(child[0]);

				if( ret < d )
				{
					ret = d;
				}
			}
		}

		return ret;
	}

	int height(BTreeNode<T>* node) const
	{
		int ret = 0;

		if( node != NULL )
		{
			int hl = height(node->left);
			int hr = height(node->right);

			if( ret < hl )
			{
				ret = hl;
			}
			if( ret < hr )
			{
				ret = hr;
			}

			ret += 1;
		}

		return ret;
	}

	void preOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
	{
		if( node != NULL )
		{
			queue.add(node);
			preOrderTraversal(node->left, queue);
			preOrderTraversal(node->right, queue);
		}
	}

	void inOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
	{
		if( node != NULL )
		{
			inOrderTraversal(node->left, queue);
			queue.add(node);
			inOrderTraversal(node->right, queue);
		}
	}

	void postOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
	{
		if( node != NULL )
		{
			postOrderTraversal(node->left, queue);
			postOrderTraversal(node->right, queue);
			queue.add(node);
		}
	}

	void levelOrderTraversal(BTreeNode<T>* node, LinkQueue<BTreeNode<T>*>& queue)
	{
		if( node != NULL )
		{
			LinkQueue<BTreeNode<T>*> tmp;
			tmp.add(node);

			while( tmp.length() > 0 )
			{
				BTreeNode<T>* slider = tmp.front();
				if( slider->left != NULL )
				{
					tmp.add( slider->left );
				}
				if( slider->right != NULL )
				{
					tmp.add( slider->right );
				}

				queue.add( slider );
				tmp.remove();
			}
		}
	}

	BTreeNode<T>* clone( const BTreeNode<T>* node ) const
	{
		BTreeNode<T>* ret = NULL;

		if( node != NULL )
		{
			ret = BTreeNode<T>::NewNode();
			if( ret )
			{
				ret->value = node->value;

				ret->left = clone(node->left);
				ret->right = clone(node->right);
				
				if( ret->left != NULL )
				{
					ret->left->parent = ret;
				}

				if( ret->right != NULL )
				{
					ret->right->parent = ret;
				}

			}
			else
			{

			}
		}

		return ret;
	}

	bool equal(BTreeNode<T>* lt, BTreeNode<T>* rt)
	{
		if( lt == rt )
		{
			return true;
		}
		else if( (lt != NULL) && (rt != NULL) )
		{
			return ( lt->value == rt->value ) && ( equal(lt->left, rt->left) ) && ( equal(lt->right, rt->right) );
		}
		else
		{
			return false;
		}
	}

	BTreeNode<T>* add(const BTreeNode<T>* lt, const BTreeNode<T>* rt) const
	{
		BTreeNode<T>* ret = NULL;

		if( ( lt != NULL ) && ( rt == NULL ) )
		{
			return clone( lt );
		}
		else if( ( lt == NULL ) && ( rt != NULL ) )
		{
			return clone( rt );
		}
		else if( ( lt != NULL ) && ( rt != NULL ) )
		{
			ret = BTreeNode<T>::NewNode();
			ret->value = lt->value + rt->value;
			ret->left = add(lt->left, rt->left);
			ret->right = add(lt->right, rt->right);

			if( ret->left != NULL )
			{
				ret->left->parent = ret;
			}

			if( ret->right != NULL )
			{
				ret->right->parent = ret;
			}
		}


		return ret;
	}

	void traversal(BTTraversal order, LinkQueue<BTreeNode<T>*>& queue)
	{
		switch(order)
		{
			case PreOrder:
				preOrderTraversal( root(), queue );
				break;

			case InOrder:
				inOrderTraversal( root(), queue );
				break;

			case PostOrder:
				postOrderTraversal( root(), queue );
				break;

			case LevelOrder:
				levelOrderTraversal( root(), queue);
				break;

			default:
					break;
					// throw();
		};
	}

	BTreeNode<T>* connect(LinkQueue<BTreeNode<T>*>& queue)
	{
		BTreeNode<T>* ret = NULL;

		if( queue.length() > 0 )
		{
			ret = queue.front();
			BTreeNode<T>* slider = queue.front();
			slider->left = NULL;
			queue.remove();

			while( queue.length() > 0 )
			{
				slider->right = queue.front();
				queue.front()->left = slider;				
				slider = queue.front();
				queue.remove();
			}

			slider->right = NULL;
		}

		return ret;
	}


public:
	bool insert(TreeNode<T>* node)
	{
		return insert(dynamic_cast<BTreeNode<T>*>(node), ANY);
	}

	bool insert(TreeNode<T>* node, BTNodePos Pos)
	{
		bool ret = true;

		if( this->m_root == NULL )
		{
			node->parent = NULL;
			this->m_root = node;
		}
		else
		{
			BTreeNode<T>* np = find( node->parent );

			if( np != NULL )
			{
				ret = insert(dynamic_cast<BTreeNode<T>*>(node), np, Pos);
			}
		}

		return ret;
	}

	bool insert(const T& value, TreeNode<T>* parent)
	{
		return insert(value, parent, ANY);
	}

	bool insert(const T& value, TreeNode<T>* parent, BTNodePos Pos)
	{
		bool ret = true;		
		BTreeNode<T>* node = BTreeNode<T>::NewNode();

		if( node != NULL )
		{		
			if( this->m_root == NULL )
			{
				node->parent = NULL;
				node->value = value;
				this->m_root = node;
			}
			else
			{
				node->parent = parent;
				node->value = value;
				ret = insert(node, dynamic_cast<BTreeNode<T>*>(parent), Pos);

				if( !ret )
				{
					delete node;
				}
			}
		}
		else
		{
			
		}

		return ret;
	}

	SharePoint< Tree<T> > remove(const T& value)
	{
		BTree<T>* ret;
		BTreeNode<T>* node = find(value);

		if( node != NULL )
		{
			remove(node, ret);
		}
		else
		{
			// throw();
		}

		return ret;
	}

	SharePoint< Tree<T> > remove(TreeNode<T>* node)
	{
		BTree<T>* ret;
		node = find(node);

		if( node != NULL )
		{
			remove(dynamic_cast<BTreeNode<T>*>(node), ret);
		}
		else
		{
			// throw();
		}

		return ret;
	}

	BTreeNode<T>* find(const T& value) const
	{
		return find(value, root());
	}

	BTreeNode<T>* find(TreeNode<T>* node) const
	{
		return find(dynamic_cast<BTreeNode<T>*>(node), root());
	}

	BTreeNode<T>* root() const
	{
		return dynamic_cast<BTreeNode<T>*>(this->m_root);
	}

	int degree() const
	{
		return degree( root() );
	}

	int count() const
	{
		return count( root() );
	}

	int height() const
	{
		return height( root() );
	}

	void clear()
	{	
		m_queue.clear();
		free( root() );
		this->m_root = NULL;
	}

	bool begin()
	{
		bool ret = ( this->m_root != NULL );

		if( ret )
		{
			m_queue.clear();
			m_queue.add( dynamic_cast<BTreeNode<T>*>(this->m_root) );
		}

		return ret;
	}

	bool end()
	{
		return ( m_queue.length() == 0 );
	}

	bool next()
	{
		bool ret = true;

		BTreeNode<T>* node = m_queue.front();
		m_queue.remove();

		if( node->left != NULL )
		{
			m_queue.add(node->left);
		}
		if( node->right != NULL )
		{
			m_queue.add(node->right);
		}

		return ret;
	}

	TreeNode<T>* current()
	{
		return m_queue.front();
	}

	SharePoint< Array<T> > traversal(BTTraversal order)
	{
		LinkQueue<BTreeNode<T>*> queue;
		DynamicArray<T>* ret = NULL;

		traversal(order, queue);

		ret = new DynamicArray<T>( queue.length() );

		if( ret != NULL )
		{
			for(int i=0; i<(ret->length()); i++, queue.remove() )
			{
				ret->set(i, queue.front()->value);			
			}
		}
		else
		{
			// throw();
		}

		return ret;
	}

	BTreeNode<T>* thread(BTTraversal order, BTreeNode<T>* node)
	{	
		BTreeNode<T>* ret = NULL;

		if( node != NULL )
		{
			LinkQueue<BTreeNode<T>*> queue;

			traversal(order, queue);

			ret = connect(queue);

			this->m_root = NULL;

			m_queue.clear();
		}

		return ret;
	}

	SharePoint< BTree<T> > clone() const
	{
		BTree<T>* ret = new BTree<T>();

		if( ret )
		{
			ret->m_root = clone( root() );
		}
		else
		{

		}

		return ret;
	}

	SharePoint< BTree<T> > add(const BTree<T>& obj) const
	{
		BTree<T>* ret = new BTree<T>();

		if( ret != NULL )
		{
			ret->m_root = add( root(), obj.root() );
		}
		else
		{

		}

		return ret;
	}

	bool operator == (const BTree<T>& obj)
	{
		return equal( root(), obj.root() );
	}

	bool operator != (const BTree<T>& obj)
	{
		return !( *this == obj );
	}


	~BTree()
	{
		clear();
	}

};




#endif