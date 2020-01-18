#ifndef _STATICARRAY_H_
#define _STATICARRAY_H_

#include <iostream>
#include "Array.h"

using namespace std;

template 
<typename T, int N>
class staticArray : public Array<T>
{
protected:
	T m_space[N];
public:
	staticArray()
	{
		this->m_array = m_space;
	}

	staticArray(const staticArray<T, N>& obj)
	{
		for(int i=0; i < this->length(); i++)
		{
			m_space[i] = obj.m_space[i];
		}
	}

	int length()
	{
		return N;
	}

	~staticArray()
	{

	}
};








































#endif