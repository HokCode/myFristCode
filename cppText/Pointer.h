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

	T& operator * ()	//T&引用返回本身，T会复制一份返回
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