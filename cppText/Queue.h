#ifndef _QUEUE_H_
#define _QUEUE_H_

template
< typename T >
class Queue
{
public:
	virtual void add(const T& e) = 0;
	virtual void remove() = 0;
	virtual T front() const = 0;
	virtual void clear() = 0;
	virtual int capacity() const = 0;
};




#endif