#ifndef _HEAPARRAY_H_
#define _HEAPARRAY_H_

using namespace std;

template
<typename T>
class HeapArray
{
	int m_length;
	T* m_pointer;
	HeapArray(int length);	//做简单赋值操作
	bool Construct();		//做申请内存操作
public:
	static HeapArray* NewInstance(int len);
	bool set(int index, T value);
	bool get(int index, T& value);
	T& operator[] (int index);
	T  operator[] (int index) const;
	HeapArray& self();
	~HeapArray();	//不用虚函数，因为构造函数在private中。
};

template
<typename T>
HeapArray<T>* HeapArray<T>::NewInstance(int len)
{
	HeapArray* ret = new HeapArray(len);
	if ( !(ret && ret->Construct()) )		//调用实体类的construct函数
	{
		delete ret;
		ret = 0;
	}

	return ret;
}

template
<typename T>
bool HeapArray<T>::Construct()
{
	m_pointer = new T(m_length);

	return m_pointer != NULL;
}

template
<typename T>
HeapArray<T>::HeapArray(int length)
{
	m_length = length;
}

template
<typename T>
bool HeapArray<T>::set(int index, T value)
{
	bool ret = (0 <= index) && (index < m_length);

	if( ret )
	{
		m_pointer[index] = value;
	}

	return ret;
}

template
<typename T>
bool HeapArray<T>::get(int index, T& value)
{
	bool ret = (0 <= index) && (index < m_length);

	if( ret )
	{
		return m_pointer[index];
	}
}

template
<typename T>
T& HeapArray<T>::operator[] (int index)
{
	return m_pointer[index];
}

template
<typename T>
T  HeapArray<T>::operator[] (int index) const
{
	return m_pointer[index];
}

template
<typename T>
HeapArray<T>& HeapArray<T>::self()
{
	return *this;
}

template
<typename T>
HeapArray<T>::~HeapArray()
{
	delete[] m_pointer;
}

/*
调用：
HeapArray<char>* ap = HeapArray<char>::NewInstance(10);

	if (ap != NULL)
	{	
		HeapArray<char>& ai = ap->self();
		for (char i = 0; i < 10; i++)
		{
			//ai.set(i, i + 'a');
			ai[i] = i + 'a';
		}
		for (char i = 0; i < 10; i++)
		{
			cout << ai[i] << endl;
		}
	}


*/











#endif