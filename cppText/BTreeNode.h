#ifndef _BTREENDOE_H_
#define _BTREENDOE_H_

#include "TreeNode.h"

template
< typename T >
class BTreeNode : public TreeNode<T>
{
public:
	BTreeNode<T>* left;
	BTreeNode<T>* right;

	BTreeNode()
	{
		left = NULL;
		right = NULL;
	}

	static BTreeNode<T>* NewNode()
	{
		BTreeNode<T>* ret = new BTreeNode<T>();

		if( ret != NULL )
		{
			ret->m_flag = true;
		}

		return ret;
	}
};










#endif