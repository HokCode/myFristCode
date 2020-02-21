#ifndef	_GTREENODE_H
#define _GTREENODE_H

#include "TreeNode.h"
#include "LinkList.h"

template
< typename T >
class GTreeNode : public TreeNode<T>
{
protected:


public:
	LinkList<GTreeNode<T>*> child;
	
	static GTreeNode<T>* NewNode()
	{
		GTreeNode<T>* ret = new GTreeNode<T>();

		if( ret != NULL )
		{
			ret->m_flag = true; //用new出来的实例类来操作成员变量m_flag
		}

		return ret;
	}
};





#endif