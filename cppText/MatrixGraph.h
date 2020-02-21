#ifndef _MATRIXGRAPH_H_
#define _MATRIXGRAPH_H_

#include "Graph.h"
#include "DynamicArray.h"

template
< int N, typename V, typename E >
class MatrixGraph : public Graph<V, E>
{
protected:
	V* m_Vertexes[N];
	E* m_edges[N][N];
	int m_eCount;

public:
	MatrixGraph()
	{
		for(int i=0; i<N; i++)
		{
			m_Vertexes[i] = NULL;
			for(int j=0; j<N; j++)
			{
				m_edges[i][j] = NULL;
			}
		}

		m_eCount = 0;
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
			if( m_Vertexes[i] != NULL )
			{
				value = *m_Vertexes[i];
			}
			else
			{
				// throw();
			}
		}

		return ret;
	}

	bool setVertex(int i, const V& value)
	{
		bool ret = (0 <= i) && (i < vCount());

		if( ret )
		{
			V* data = m_Vertexes[i];

			if( data == NULL )
			{
				data = new V();
			}
			
			if( data != NULL )
			{
				*data = value;

				m_Vertexes[i] = data;
			}
		}

		return ret;
	}

	SharePoint< Array<int> > getAdjacent(int i)
	{
		bool ret = (0 <= i) && (i < vCount());

		DynamicArray<int>* aj = NULL;

		if( ret )
		{
			int n = 0;
			for(int j=0; j<vCount(); j++)
			{
				if( m_edges[i][j] != NULL )
				{
					n++;
				}
			}

			aj = new DynamicArray<int>(n);

			if( aj != NULL )
			{
				for(int j=0, k=0; j<vCount(); j++)
				{
					if( m_edges[i][j] != NULL )
					{
						aj->set(k++, j);
					}
				}
			}
			else
			{
				// throw();
			}
			
		}
		else
		{
			// throw();
		}

		return aj;
	}

	E getEdge(int i, int j)
	{
		E ret;

		if( !getEdge(i, j, ret) )
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
			if( m_edges[i][j] != NULL )
			{
				value = *m_edges[i][j];
			}
			else
			{
				// throw();
			}
		}

		return ret;
	}

	bool setEdge(int i, int j, const E& value)
	{
		bool ret = ((0 <= i) && (i < vCount()) &&
					(0 <= j) && (j < vCount()));

		if( ret )
		{
			E* data = m_edges[i][j];

			if( data == NULL )
			{
				data = new E();
			}
			if( data != NULL )
			{
				*data = value;

				m_edges[i][j] = data;

				m_eCount++;
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
			E* toDel = m_edges[i][j];

			m_edges[i][j] = NULL;

			if( toDel != NULL )
			{
				delete toDel;
			}

			m_eCount--;
		}

		return ret;
	}

	int vCount()
	{
		return N;
	}

	int eCount()
	{
		return m_eCount;
	}

	int OD(int i)
	{
		bool ret = (0 <= i) && (i < vCount());
		int n = 0;
		if( ret )
		{
			for(int j=0; j<vCount(); j++)
			{
				if( m_edges[i][j] != NULL )
				{
					n++;
				}
			}
		}

		return n;
	}

	int ID(int i)
	{
		bool ret = (0 <= i) && (i < vCount());
		int n = 0;
		if( ret )
		{
			for(int j=0; j<vCount(); j++)
			{
				if( m_edges[j][i] != NULL )
				{
					n++;
				}
			}
		}

		return n;
	}

	~MatrixGraph()
	{
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if( m_edges[i][j] != NULL )
				{
					delete m_edges[i][j];
				}
			}

			if( m_Vertexes[i] != NULL )
			{
				delete m_Vertexes[i];
			}
		}
	}
};








#endif