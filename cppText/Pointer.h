#ifndef _POINT_H_
#define _POINT_H_

template
< typename T >
class Pointer
{
protected:
	T* m_pointer;
public:
	Pointer(T* pn = NULL)
	{
		m_pointer = pn;
	}
	T* operator -> ()
	{
		return m_pointer;
	}

	T operator * ()
	{
		return *m_pointer;
	}

	T* get()
	{
		return m_pointer;
	}

	virtual ~Pointer()
	{
		
	}

};

























#endif