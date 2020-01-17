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
	bool set(int index, T value);
	bool get(int index, T& value);
	T& operator[] (int index);
	T operator[] (int index) const;
	virtual int capacity() = 0;
};


#endif