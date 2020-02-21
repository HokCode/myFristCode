#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>

using namespace std;

template
<typename T>
class Array
{
protected:
	T* m_array;
public:
	bool set(int index, T value)
	{
		bool ret = ((0 <= index) && (index < this->length()));
		
		if( ret )
		{
			m_array[index] = value;
		}
		else
		{
			throw("set(),out of space!");
		}

		return ret;
	}

	bool get(int index, T& value)
	{
		bool ret = ((0 <= index) && (index < this->length()));
		
		if( ret )
		{
			value = m_array[index];
		}
		else
		{
			throw("get(),out of space!");
		}

		return ret;
	}

	T& operator[] (int index)
	{
		return m_array[index];
	}

	T operator[] (int index) const
	{
		return (const_cast<Array<T>&>(*this)[index]);
	}

	virtual int length() const = 0;
};


#endif