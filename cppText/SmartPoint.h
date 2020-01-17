#ifndef _SMARTPOINT_H_
#define _SMARTPOINT_H_

template
<typename T>
class SmartPoint
{
	T* mp;
public:
	SmartPoint(T* p);
	SmartPoint(const SmartPoint<T>& obj);
	SmartPoint<T>& operator = (SmartPoint<T>& obj);
	T* operator ->();
	T& operator * ();
	T* get();
	~SmartPoint();
};

template
<typename T>
SmartPoint<T>::SmartPoint(T* p)
{
	mp = p;
}

template
<typename T>
SmartPoint<T>::SmartPoint(const SmartPoint<T>& obj)
{
	mp = obj.mp;
	const_cast<SmartPoint<T>&>(obj).mp = NULL;
}

template
<typename T>
SmartPoint<T>& SmartPoint<T>::operator = (SmartPoint<T>& obj)
{
	if(&obj != this)
	{
		delete mp;
		mp = obj.mp;
		const_cast<SmartPoint<T>&>(obj).mp = NULL;
	}
	return *this;
}

template
<typename T>
T* SmartPoint<T>::operator ->()
{
	return mp;
}

template
<typename T>
T& SmartPoint<T>::operator * ()
{
	return *mp;
}

template
<typename T>
T* SmartPoint<T>::get()
{
	return mp;
}

template
<typename T>
SmartPoint<T>::~SmartPoint()
{
	delete mp;
}


#endif