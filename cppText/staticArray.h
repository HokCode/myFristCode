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

	bool set(int index, T value)
	{
		bool ret = ((0 <= index) && (index < this->capacity()));
		
		if( ret )
		{
			m_space[index] = value;
		}
		else
		{
			throw("set(),out of space!");
		}

		return ret;
	}

	bool get(int index, T& value)
	{
		bool ret = ((0 <= index) && (index < this->capacity()));
		
		if( ret )
		{
			value = m_space[index];
		}
		else
		{
			throw("get(),out of space!");
		}

		return ret;
	}

	T& operator[] (int index)
	{
		return m_space[index];
	}

	T operator[] (int index) const
	{
		return (const_cast<staticArray<T,N>&>(*this)[index]);
	}

	int capacity()
	{
		return N;
	}

	~staticArray()
	{

	}
};








































#endif