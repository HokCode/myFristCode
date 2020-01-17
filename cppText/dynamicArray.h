#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "Array.h"

template
<typename T>
class dynamicArray : public Array<T>
{
protected:
	int length;
public:
	dynamicArray(int capacity)
	{
		T* array = new T[capacity];

		if(T* array != NULL)
		{
			this->m_array = array;
			this->length = capacity;
		}
		else
		{
			throw("Application memory error!!");
		}
	}
}
































#endif