#ifndef _STACK_H_
#define _STACK_H_

template
< typename T >
class Stack
{
public:
	virtual void push(const T& e) = 0;
	virtual void pop() = 0;
	virtual T top() const = 0;
	virtual int size() const = 0;
	virtual void clear() = 0;
};



























#endif