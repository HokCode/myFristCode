#ifndef _SMARTPOINT_H_
#define _SMARTPOINT_H_

#include "Pointer.h"

template
<typename T>
class SmartPoint : public Pointer<T>
{

public:
	SmartPoint(T* pn) : Pointer<T>(pn)
	{

	}

	SmartPoint(const SmartPoint<T>& obj)
	{
		this->m_pointer = obj.m_pointer;
		const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;
	}

	SmartPoint<T>& operator = (const SmartPoint<T>& obj)
	{
		if( this != &obj )
		{
			T* tmp = this->m_pointer;
			this->m_pointer = obj.m_pointer;
			const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;

			delete tmp;
		}

		return *this;
	}

	~SmartPoint()
	{
		delete this->m_pointer;
	}
};


#endif