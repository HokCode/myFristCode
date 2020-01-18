#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "Array.h"

template
<typename T>
class dynamicArray : public Array<T>
{
protected:
	int m_length;
public:
	dynamicArray(int capacity)
	{
		this->m_array = new T[capacity];

		if( this->m_array != NULL)
		{
			this->length = capacity;
		}
		else
		{
			throw("Application memory error!!");
		}
	}

	T& operator =  (const dynamicArray<T>& obj)
	{
		T* array = new T[obj.length()];

		if( array != NULL )
		{
			int size = this->m_length < obj.m_length ? this->m_length : obj.m_length;

			for(int i=0; i< size; i++)
			{
				this->m_array[i] = obj.m_array[i];
			}

			T* temp = this->m_array;
			this->m_array = array;
			this->m_length = obj.m_length;

			delete[] temp;
		}
		else
		{
			throw("");
		}
	}

	int length()
	{
		return m_length;
	}

	~dynamicArray()
	{
		delete[] this->m_array;
	}
};
































#endif