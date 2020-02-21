#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <cstring>
#include <cstdlib>

// #include "object.h"

#define THROW_EXCEPTION(e, s)  throw e(s, __FILE__, __LINE__);

class Exception
{
public:
    char *m_message;
    char *m_location;

    void init(const char* message, const char* file, int line)
    {
        m_message = strdup(message); //char* strdup(char* s).using malloc inside,must free in the end;

        if(file != NULL)
        {
            char s1[16] = {0};
            itoa(line, s1, 11); //½²line×ª»¯ÎªcharÀàÐÍ£¬´æÈës1ÖÐ¡£

            m_location = static_cast<char*>(malloc(strlen(file) + strlen(s1) + 2));

            if(m_location != NULL)
            {
                m_location = strcpy(m_location, file);
                m_location = strcat(m_location, ":");
                m_location = strcat(m_location, s1);
            }
        }
        else
        {
            m_location = NULL;
        }
    }

public:
    Exception(const char* message)
    {
        init(message, NULL, 0);
    }

    Exception(const char* file, int line)
    {
        init(NULL, file, line);
    }

    Exception(const char* message, const char* file, int line)
    {
        init(message, file, line);
    }

    Exception(const Exception& e)
    {
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    Exception& operator =(const Exception& e)
    {
        if(this != &e)
        {
            free(m_message);
            free(m_location);

            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);
        }

        return *this;
    }

    const char* message() const
    {
        return m_message;
    }

    const char* location() const
    {
        return m_location;
    }

    ~Exception()
    {
        free(m_message);
        free(m_location);
    }
};


#endif // EXCEPTION_H
