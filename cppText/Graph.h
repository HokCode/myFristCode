#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "SharePoint.h"
#include "Array.h"

template
< typename E >
struct Edge
{
	int b;
	int e;
	E m_edge;

	Edge( int i = -1, int j = -1)
	{
		b = i;
		e = j;
	}

	Edge( int i, int j, const E& value )
	{
		b = i;
		e = j;
		m_edge = value;
	}

	bool operator == (const Edge& obj)
	{
		return ( b == obj.b ) && ( e == obj.e );
	}

	bool operator != (const Edge& obj)
	{
		return !(*this == obj);
	}
};

template
< typename V, typename E >
class Graph
{
public:
	virtual V getVertex(int i) = 0;		//Vertex,顶点
	virtual bool getVertex(int i, V& value) = 0;
	virtual bool setVertex(int i, const V& value) = 0;
	virtual SharePoint< Array<int> > getAdjacent(int i) = 0; //Adjacent,相邻的。实现i相邻的顶点，i可以去的顶点
	virtual E getEdge(int i, int j) = 0;
	virtual bool getEdge(int i, int j, E& value) = 0;
	virtual bool setEdge(int i, int j, const E& value) = 0;
	virtual bool removeEdge(int i, int j) = 0;
	virtual int vCount() = 0;
	virtual int eCount() = 0;
	virtual int OD(int i) = 0;
	virtual int ID(int i) = 0;

	virtual int TD(int i)
	{
		return OD(i) + ID(i);
	}
};








#endif