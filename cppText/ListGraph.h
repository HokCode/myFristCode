#ifndef _LISTGRAPH_H_
#define _LISTGRAPH_H_

#include "Graph.h"
#include "LinkList.h"
#include "DynamicArray.h"

template
< typename V, typename E >
class ListGraph : public Graph<V, E>
{
protected:
	struct Vertex
	{
		V* data;
		LinkList< Edge<E> > edge;

		Vertex()
		{
			data = NULL;
		}
	};

	LinkList<Vertex*> m_List;

public:
	ListGraph( unsigned int n = 0 )
	{
		for(unsigned int i=0; i<n; i++)
		{
			addVertex();
		}
	}


	int addVertex()
	{
		int ret = -1;

		Vertex* vertex = new Vertex();
		if( vertex != NULL )
		{
			ret = m_List.length() - 1;
			m_List.insert(vertex);
		}
		else
		{
			// throw();
		}

		return ret;
	}

	V getVertex(int i)
	{
		V ret;

		if( !getVertex(i, ret) )
		{
			// throw();
		}

		return ret;
	}

	bool getVertex(int i, V& value)
	{
		bool ret = (0 <= i) && (i < vCount());

		if( ret )
		{
			Vertex* vertex = m_List.get(i);

			if( vertex->data != NULL )
			{
				value = *(vertex->data);				
			}
		}
		else
		{
			// throw();
		}

		return ret;
	}

	bool setVertex(int i, const V& value)
	{
		bool ret = (0 <= i) && (i < vCount());

		if( ret )
		{
			Vertex* vertex = m_List.get(i);

			if( vertex->data == NULL )
			{
				vertex->data = new V();
			}
			if( vertex->data != NULL )
			{
				*(vertex->data) = value;
			}
		}
		else
		{
			// throw();
		}

		return ret;
	}

	void removeVertex()
	{
		if( m_List.length() > 0 )
		{
			int i = m_List.length() - 1;
			Vertex* toDel = m_List.get(i);
			
			if( m_List.remove(i) )
			{
				for(int j=(m_List.move(0), 0); !m_List.end(); m_List.next(), j++)
				{
					int pos = m_List.current()->edge.find(Edge<E>(j, i));

					if( pos >= 0 )
					{
						m_List.current().edge.remove(pos);
					}

				}
			}
			
			delete toDel->data;
			delete toDel;
		}
		else
		{
			// throw();
		}
	}

	SharePoint< Array<int> > getAdjacent(int i)
	{
		bool ret = (0 <= i) && (i < vCount());
		DynamicArray<int>* aj = NULL;

		if( ret )
		{
			Vertex* vertex = m_List.get(i);
			aj = new DynamicArray<int>( vertex->edge.length() );

			if( aj != NULL )
			{
				for(int k=(vertex->edge.move(0), 0); !vertex->edge.end(); vertex->edge.next(), k++)
				{
					aj->set(k, vertex->edge.current().e);
				}
			}
		}

		return aj;
	}

	E getEdge(int i, int j)
	{
		E ret;

		if( !getEdge(i, j, ret) )
		{

		}
		else
		{
			// throw();
		}

		return ret;
	}

	bool getEdge(int i, int j, E& value)
	{
		bool ret = ((0 <= i) && (i < vCount()) &&
					(0 <= j) && (j < vCount()));

		if( ret )
		{
			Vertex* vertex = m_List.get(i);

			int pos = vertex->edge.find(Edge<E>(i, j));

			if( pos >= 0 )
			{
				value = vertex->edge.get(pos).m_edge;
			}
		}
		else
		{
			// throw();
		}

		return ret;
	}

	bool setEdge(int i, int j, const E& value)
	{
		bool ret = ((0 <= i) && (i < vCount()) &&
					(0 <= j) && (j < vCount()));

		if( ret )
		{
			Vertex* vertex = m_List.get(i);
			int pos = vertex->edge.find(Edge<E>(i, j));

			if( pos >= 0 )
			{
				vertex->edge.set(pos, value);
			}
			else
			{
				vertex->edge.insert(Edge<E>(i, j, value));
			}
		}

		return ret;
	}

	bool removeEdge(int i, int j)
	{
		bool ret = ((0 <= i) && (i < vCount()) &&
					(0 <= j) && (j < vCount()));

		if( ret )
		{
			Vertex* vertex = m_List.get(i);
			int pos = vertex->edge.find(Edge<E>(i, j));

			if( pos >= 0 )
			{
				vertex->edge.remove(pos);
			}
			else
			{
				// throw();
			}
		}

		return ret;
	}

	int vCount()
	{
		return m_List.length();
	}

	int eCount()
	{
		int ret = 0;

		for(m_List.move(0); !m_List.end(); m_List.next())
		{
			ret += m_List.current()->edge.length();
		}

		return ret;
	}

	int OD(int i)
	{
		return m_List.get(i)->edge.length();
	}

	int ID(int i)
	{
		int ret = 0;

		for(m_List.move(0); !m_List.end(); m_List.next())
		{
			LinkList< Edge<E> >& edge = m_List.current()->edge;
			for(edge.move(0); !edge.end(); edge.next())
			{
				if(edge.current().e == i)
				{
					ret++;
				}
			}
		}

		return ret;
	}
};



#endif