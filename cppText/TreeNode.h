#ifndef _TREENODE_H_
#define _TREENODE_H_


template
< typename T >
class TreeNode
{
protected:
	TreeNode(const TreeNode<T>&);
	TreeNode<T>& operator = (const TreeNode<T>&);

	bool m_flag;

	void* operator new (unsigned int size) throw()
	{
		return malloc(size);
	}

public:
	T value;
	TreeNode<T>* parent;
	TreeNode()
	{
		parent = NULL;
		m_flag = false;
	}

	bool flag()
	{
		return m_flag;
	}

	virtual ~TreeNode() = 0;
};

template
< typename T >
TreeNode<T>::~TreeNode()
{

}



#endif