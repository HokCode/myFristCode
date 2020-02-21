#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <typeinfo>

#include "staticArray.h"
#include "HeapArray.h"
#include "Array.h"
#include "SmartPoint.h"
#include "DynamicArray.h"
#include "LinkList.h"
#include "Exception.h"
#include "SharePoint.h"
#include "Pointer.h"
#include "CircleList.h"
#include "DualLinkList.h"
#include "LinuxList.h"
#include "DualCircleList.h"
#include "StaticStack.h"
#include "LinkStack.h"
#include "StaticQueue.h"
#include "LinkQueue.h"
#include "GJString.h"
#include "Sort.h"

#include "TreeNode.h"
#include "GTreeNode.h"
#include "BTreeNode.h"
#include "Tree.h"
#include "GTree.h"
#include "BTree.h"

#include "Graph.h"
#include "MatrixGraph.h"
#include "ListGraph.h"

using namespace std;

template
< typename T >
BTreeNode<T>* delOdd1(BTreeNode<T>* node)
{
	BTreeNode<T>* ret = NULL;

	if( node != NULL )
	{
		if( (( node->left != NULL ) && ( node->right == NULL )) ||
			(( node->left == NULL ) && ( node->right != NULL )) )
		{	
			BTreeNode<T>* parent = dynamic_cast<BTreeNode<T>*>(node->parent);
			BTreeNode<T>* node_child = ( node->left == NULL ) ? node->right : node->left;

			if( parent != NULL )
			{
				BTreeNode<T>*& parent_child = ( parent->left == node ) ? parent->left : parent->right;
				parent_child = node_child;
				node_child->parent = parent;			
			}
			else
			{
				node_child->parent = NULL;
			}

			if( node->flag() )
			{
				delete node;
			}

			ret = delOdd1( node_child );
		}
		else
		{
			delOdd1( node->left );
			delOdd1( node->right );

			ret = node;
		}
	}

	return ret;
}

template
< typename T >
void delOdd2(BTreeNode<T>*& node)
{
	if( node != NULL )
	{
		if(((node->left != NULL) && (node->right == NULL)) || 
		   ((node->left == NULL) && (node->right != NULL))	)
		{
			BTreeNode<T>* parent_child = (node->left == NULL) ? node->right : node->left;

			if( node->flag() )
			{
				delete node;
			}

			node = parent_child;

			delOdd2(node);
		}
	}
	else
	{
		delOdd2(node->left);
		delOdd2(node->right);
	}
}

// template
// < typename T >
// void inOrderThread1(BTreeNode<T>* node, BTreeNode<T>*& head, BTreeNode<T>*& tail)
// {

// 	if( node != NULL )
// 	{

// 		cout << node->value << endl;
// 		BTreeNode<T>* h = NULL;
// 		BTreeNode<T>* t = NULL;

// 		inOrderThread1(node->left, h, t);	//返回后，h指向左子树头结点，t指向左子树尾结点

// 		node->left = t;

// 		if( t != NULL )
// 		{
// 			t->right = node;
// 		}

// 		head = ( h != NULL ) ? h : node;

// 		h = NULL;
// 		t = NULL;

// 		inOrderThread1(node->right, h, t);

// 		node->right = h;

// 		if( h != NULL )
// 		{
// 			h->left = node;
// 		}

// 		tail = ( t != NULL ) ? t : node;
// 	}
// }

template
< typename T >
void inOrderThread1(BTreeNode<T>* node, BTreeNode<T>*& head, BTreeNode<T>*& tail)
{
	if( node != NULL )	
	{
		BTreeNode<T>* h = NULL;
		BTreeNode<T>* t = NULL;

		inOrderThread1(node->left, h, t);

		if( h == NULL )	//左子树head结点固定不动
		{
			h = node;
		}

		node->left = t;

		if( t != NULL)
		{
			t -> right = node;
		}

		t = node;

		head = ( h != NULL ) ? h : node;

		h = NULL;
		t = NULL;

		inOrderThread1(node->right, h, t);

		if( t == NULL )
		{
			t = node;
		}

		node->right = h;

		if( h != NULL )
		{
			h->left = node;
		}

		h = node;

		tail = ( t != NULL ) ? t : node;

	}
}

template
< typename T >
BTreeNode<T>* inOrderThread2(BTreeNode<T>* node)
{
	BTreeNode<T>* head = NULL;
	BTreeNode<T>* tail = NULL;

	inOrderThread1(node, head, tail);

	return head;
}

template
< typename T >
void _inOrderThread(BTreeNode<T>* node, BTreeNode<T>*& pre)	//pre要用引用，需要用结点别名不能另外复制
{
	if( node != NULL )
	{
		_inOrderThread(node->left, pre);

		node->left = pre;
		if( pre != NULL)
		{
			pre->right = node;
		}
		pre = node;

		_inOrderThread(node->right, pre);
	}

}

template
< typename T >
BTreeNode<T>* inOrderThread(BTreeNode<T>* n)
{
	BTreeNode<T>* pre = NULL;
	_inOrderThread(n, pre);

	while( ( n != NULL ) && ( n->left != NULL ) )
	{
		cout << n->value << " ";
		n = n->left;
	}
	cout << endl;

	return n;
}

template
< typename T >
void levelPrint(BTreeNode<T>* node)
{
	LinkQueue<BTreeNode<T>*> queue;
	if( node != NULL)
	{
		queue.add(node);

		while( queue.length() > 0 )
		{
			BTreeNode<T>* n = queue.front();
			cout << n->value << " ";
			queue.remove();

			if( n->left != NULL )
			{
				queue.add(n->left);
			}
			if( n->right != NULL )
			{
				queue.add(n->right);
			}
		}

		cout << endl;
	}
	

}


int main()
{
	// BTreeNode<int> a[5];
	// int c[5] = {0, 6, 2, 7, 8};
	// for(int i=0; i<5; i++)
	// {
	// 	a[i].value = c[i];
	// 	a[i].parent = NULL;
	// 	a[i].left = NULL;
	// 	a[i].right = NULL;
	// }

	// a[0].left = &a[1];
	// a[0].right = &a[2];

	// a[2].left = &a[3];
	// a[2].right = &a[4];

	// BTreeNode<int>* n = inOrderThread(&a[0]);
	// while( n != NULL )
	// {
	// 	cout << n->value << " ";
	// 	n = n->right;
	// }
	// cout << endl;

	// Graph<int, int>* p = NULL;

	ListGraph<char, int> g(4);

	g.setVertex(0, 'A');
	g.setVertex(1, 'B');
	g.setVertex(2, 'C');
	g.setVertex(3, 'D');

	g.setEdge(0, 1, 5);
	g.setEdge(0, 3, 6);
	g.setEdge(1, 2, 8);
	g.setEdge(2, 3, 2);
	g.setEdge(3, 1, 6);

	// cout << "V0: " << g.getVertex(0) << endl;

	// cout << "B, OD:" << g.ID(1) << endl;

	g.removeEdge(3, 1);

	cout << "W(3, 1) " << g.getEdge(3, 1) << endl;

	return 0;

}