#ifndef SEQLIST_H
#define SEQLIST_H

#include "List.h"
#include "exception.h"

namespace GJlib
{

template < typename T >
class SeqList : public List<T>
{
protected:
    T* m_array;
    int m_length;
public:
    SeqList()
    {

    }

    //����Ԫ��
    bool insert(int i, const T& e)
    {
        bool ret = (0 <= i)&&(i <= m_length);

        ret = ret && ( m_length + 1 <= capacity );

        if( ret )
        {
            for(int p = m_length-1; p>=i; p--)
            {
                m_array[p + 1] = m_array[p];
            }

            m_array[i] = e;
            m_length++;
        }

        return ret;
    }

    //Ĭ�ϲ������Ա�ĩ�˺���
    bool insert(const T& e)
    {
        return insert(m_length, e);
    }

    //�Ƴ�Ԫ��
    bool remove(int i)
    {
        bool ret = ( 0 <= i)&&( i < m_length);

        if( ret )
        {
            for(int p = i; p < m_length-1; p++)
            {
                m_array[p] = m_array[p + 1];
            }

            m_length--;
        }

        return ret;
    }

    //��ȡԪ��
    bool get(int i, T& e)const
    {
        bool ret = (0 <= i)&&(i < m_length);

        if( ret )
        {
            e = m_array[i];
        }

        return ret;
    }

    //����Ԫ��
    bool set(int i, const T& e)
    {
        bool ret = (0 <= i)&&(i < m_length);

        if( ret )
        {
            m_array[i] = e;
        }

        return ret;
    }

    //�õ����Ա���
    int length() const
    {
        return m_length
    }

    //������Ա�
    void clear()
    {
        m_length = 0;
    }

    T& operator[] (int i)
    {
        if( (0 <= i)&&(i < m_length) )
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(Exception, "Parameter i is invalid ...")
        }
    }

    T operator[] (int i) const
    {
        return (const_cast<SeqList<T>&>(*this))[i];
    }

    virtual int capacity() const = 0;
};

}


#endif // SEQLIST_H






