#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include "Seqlist.h"

namespace GJlib
{

template< typename T >
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;
public:
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];//申请连续堆空间作为顺序存储空间

        if( m_array != NULL )
        {
            m_length = 0;
            m_capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(Exception, "no memory to create DynamicList Object...");
        }
    }

    int capacity() const
    {
        return m_capacity;
    }

    void resize(int capacity)   //动态设置存储空间大小
    {
        T* array = new T[capacity];

        if( array != NULL )
        {
            int length = ( this->m_length < capacity ? this->m_length : capacity );

            for( int i=0; i < length; i++ )
            {
                array[i] = this->m_array[i];
            }

            T* temp = m_array;

            m_array = array;
            m_capacity = capacity;
            m_length = length;

            delete[] temp;
        }
        else
        {
            THROW_EXCEPTION(Exception, "no memory to create DynamicList Object...");
        }
    }
};


}




#endif // DYNAMICLIST_H



















