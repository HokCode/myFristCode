#ifndef _SHAREPOINT_H_
#define _SHAREPOINT_H_

#include "Pointer.h"
#include "Exception.h"
#include <iostream>

template
< typename T >
class SharePoint : public Pointer<T>
{
protected:
	int* ref;

public:
	SharePoint(T* pn = NULL) : ref(NULL)
	{		
		if( pn )
		{
			// this->ref = static_cast<int*>(malloc(sizeof(int)));
			ref = new (int);

			if( this->ref )
			{
				*(this->ref) = 1;
				this->m_pointer = pn;
			}
			else
			{
				// cout << "no enough memory..." << endl;
			}
		}
		// ref = new (int);
		// if( ref )
		// {
		// 	*ref = 1;
		// }

		// this->m_pointer = pn;
	}

	SharePoint(const SharePoint<T>& obj)
	{
		assign(obj);
	}

	SharePoint& operator = (const SharePoint<T>& obj)
	{
		if( this != &obj )
		{
			clear();
			assign(obj);
		}


		return *this;
	}

	void assign(const SharePoint<T>& obj)
	{
		this->m_pointer = const_cast<SharePoint<T>&>(obj).m_pointer;
		this->ref = const_cast<SharePoint<T>&>(obj).ref;

		//*(this->ref)++;
		//要先判断ref是否指向合法空间
		if( this->ref )
			{
				*(this->ref)++;
			}
	}

	void clear()
	{
		T* tmp_point = this->m_pointer;
		int* tmp_ref = this->ref;
		this->m_pointer = NULL;
		this->ref = NULL;

		if( tmp_ref )
		{
			(*tmp_ref)--;
			if( *tmp_ref == 0 )
			{
				// free(tmp_ref);

				delete tmp_ref;
				delete tmp_point;
			}
		}
	}

	~SharePoint()
	{
		clear();
		// T* tmp_point = this->m_pointer;
		// int* tmp_ref = this->ref;

		// if( tmp_ref )
		// {
		// 	(*tmp_ref)--;
		// 	if( *tmp_ref == 0 )
		// 	{
		// 		delete tmp_point;
		// 	}
		// }
	}

};
































#endif