#ifndef STATICLIST_H
#define STATICLIST_H

#include "Seqlist.h"

namespace GJlib
{

template< typename T ,int N >
class StaticList : public SeqList<T>
{
protected:
    T m_space[N];   //Ô­ÉúÊý×é×÷Îª´æ´¢¿Õ¼ä
public:
    StaticList()
    {
        this->m_array = m_space;    //¹ØÁª¸¸ÀàÖ¸ÕëÓë´æ´¢¿Õ¼ä
        this->m_length = 0;         //ÏßÐÔ±í³¤¶È³õÊ¼»¯Îª0
    }

    int capacity() const
    {
        return N;
    }
};

}



#endif // STATICLIST_H
