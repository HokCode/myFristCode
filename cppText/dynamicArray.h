#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "Array.h"

template
<typename T>
class DynamicArray : public Array<T>
{
protected:
	int m_length;
public:
	DynamicArray(int capacity)
	{
		this->m_array = new T[capacity];

		if( this->m_array != NULL)
		{
			this->m_length = capacity;
		}
		else
		{
			throw("Application memory error!!");
		}
	}

	DynamicArray(const DynamicArray<T>& obj)
	{
		this->m_array = new T[obj.m_length];

		if(  this->m_array != NULL)
		{
			this->m_length = obj.m_length;

			for (int i=0; i<obj.m_length; i++)
			{
				this->m_array[i] = obj.m_array[i];
			}
		}
		else
		{

		}
	}

	T& operator =  (const DynamicArray<T>& obj)
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

	int length() const
	{
		return m_length;
	}

	void resize(int length)
	{
		if( length != m_length )
		{
			T* array = new T[length];

			if( array != NULL )
			{
				int size = (length < m_length) ? length : m_length;
				for(int i=0; i<size; i++)
				{
					array[i] = this->m_array[i];
				}

				T* tmp = this->m_array;
				this->m_array = array;
				delete tmp;
			}
			else
			{

			}
		}
	}

	~DynamicArray()
	{
		delete[] this->m_array;
	}
};
































#endif