#ifndef SMARTPOINT_H
#define SMARTPOINT_H

#include <iostream>
//using namespace GJlib;

#include "object.h"

namespace GJlib
{
template<typename T>
class Smartpoint : public Object
{
    T* m_point;
public:
    Smartpoint(T* p)
    {
        m_point = p;
    }

    Smartpoint(const Smartpoint<T>& obj)
    {
        delete m_point;

        m_point = obj.m_point;
        const_cast<Smartpoint<T>&>(obj).m_point = NULL;
    }

    Smartpoint<T>& operator =(Smartpoint<T>& obj)
    {
        if(this != &obj)
        {
            delete this->m_point;

            this->m_point = obj.m_point;
            obj.m_point = NULL;
        }

        return *this;
    }

    T operator *()
    {
        return *m_point;
    }

    T* operator ->()
    {
        return m_point;
    }

    ~Smartpoint()
    {
        //cout<< "~Smartpoint()" <<endl;
        delete m_point;
    }

};

}

#endif // SMARTPOINT_H

