#ifndef _GJSTRING_H_
#define _GJSTRING_H_

#include <iostream>

class String
{
protected:
	char* m_str;
	int m_length;

	void init(const char* s)
	{
		m_str = strdup(s);

		if( m_str )
		{
			m_length = strlen(s);
		}
		else
		{

		}
	}

	bool equal(const char* l, const char* j, int len) const
	{
		bool ret = true;

		for(int i=0; i<len && ret; i++)
		{
			ret = (l[i] == j[i]);
		}

		return ret;
	}

	static int* get_pmt(const char* p)
	{	
		int len = strlen(p);
		int* ret = static_cast<int*>(malloc(sizeof(int) * len));

		if( ret != NULL)
		{
			int ll = 0;
			ret[0] = 0;

			for(int i=1; i<len; i++)
			{	
				while( (ll > 0) && (p[ll] != p[i]) )
				{
					ll = ret[ll - 1];
				}

				if( p[ll] == p[i] )
				{
					ll++;
				}

				ret[i] = ll;	
			}
		}
		

		return ret;	
	}

	static int kmp(const char* s, const char* p)
	{
		int ret = -1;
		int sl = strlen(s);
		int pl = strlen(p);
		int len = sl - pl;

		int* pmt = get_pmt(p);

		if((pmt != NULL) && (p != "") && (sl >= pl))
		{
			for(int i=0, j=0; i<sl; i++)
			{
				if( (j > 0) && (s[i] != p[j]) )	//第j位不相等，代表匹配了j-1位
				{
					j = pmt[j - 1];
				}

				if( s[i] == p[j] )
				{
					j++;
				}

				if( j == pl )
				{
					ret = i + 1 - pl;
					break;
				}
			}
		}

		free(pmt);

		return ret;

	}

public:
	String()
	{
		init("");
	}

	String(const String& str)
	{
		char* s = str.m_str;
		init(s);
	}

	String(const char* s)
	{
		s = s ? s : "";
		init(s);
	}

	String(const char c)
	{
		char s[] = {c, '\0'};
		init(s);
	}

	String& operator = (const char* s)
	{
		s = s ? s : "";
		init(s);
	}

	char& operator [] (int i)
	{	
		if((0 <= i) && (i < m_length))
		{
			return m_str[i];
		}
		else
		{

		}
	}

	char operator [] (int i) const
	{	
		return const_cast<String&>(*this)[i];
	}

	String operator - (const char* s)
	{
		return String(*this).remove(s);
	}

	String operator - (const String& s)
	{
		return String(*this).remove(s.m_str);
	}

	String& operator -= (const char* s)
	{
		return remove(s);
	}

	String& operator -= (const String& s)
	{
		return remove(s.m_str);
	}

	bool startWith(const char* s) const
	{
		bool ret = (s != NULL);
		if( ret )
		{
			int len = strlen(s);

			ret = (len < m_length) && equal(m_str, s, len);
		}
		else
		{

		}

		return ret;
	}

	bool startWith(const String& s) const
	{
		return startWith(s.m_str);
	}

	bool endof(const char* s) const
	{
		bool ret = (s != NULL);
		if( ret )
		{	
			int len = strlen(s);
			ret = (len < m_length) && equal(&m_str[m_length-len], s, len);
		}
		else
		{

		}
	}

	String sub(int i, int len)
	{
		String ret;

		if((0 <= i) && (i < m_length))
		{
			if(len < 0) len = 0;
			if(i + len > m_length) len = m_length - i;

			char* str = reinterpret_cast<char*>(malloc(sizeof(char[len + 1])));
			if( str != NULL )
			{
				strncpy(str, m_str + i, len);

				str[len] = '\0';

				ret = str;
			}
		}
		else
		{

		}

		return ret;
	}

	bool endof(const String& s) const
	{
		return endof(s.m_str);
	}

	String& insert(int i, const char* s)
	{
		if(s != NULL && (0 <= i) && (i <= m_length))
		{
			int len = strlen(s);
			char* str = reinterpret_cast<char*>(malloc(sizeof(char[m_length + len + 1])));
			
			if(str != NULL)
			{
				strncpy(str, m_str, i);
				strncpy(str + i, s, len);
				strncpy(str + i + len, m_str + i, m_length - i);

				str[m_length + len] = '\0';
				m_length = m_length + len;

				free(m_str);
				m_str = str;

				return *this;
			}
			else
			{

			}
		}
	}

	String& insert(int i, const String& s)
	{
		return insert(i, s.m_str);
	}

	String& remove(int i, int len)
	{
		if((0 <= i) && (i < m_length))
		{
			int n = i;
			int m = i + len;

			while((n < m) && (m < m_length))
			{
				m_str[n++] = m_str[m++];
			}

			m_str[n] = '\0';
			m_length = n;
		}
	}

	String& remove(const char* s)
	{
		return remove(indexOf(s),s ? strlen(s) : 0);
	}

	String& remove(const String& s)
	{
		return remove(s.m_str);
	}

	int indexOf(const char* s)
	{
		return kmp(m_str, s ? s : "");
	}

	int indexOf(const String& s)
	{
		return indexOf(s.m_str);
	}

	String& replace(const char* t, const char* l)
	{
		int i = indexOf(t);

		if( i >= 0 )
		{
			remove(t);
			insert(i, l);
		}
	}

	String& replace(const String& s, const String& l)
	{
		return replace(s.m_str, l.m_str);
	}

	String& replace(const char* t, const String& l)
	{
		return replace(t, l.m_str);
	}

	String& replace(const String& s, const char* l)
	{
		return replace(s.m_str, l);
	}

	String& trim()	//clear ' ' in beginning and endding
	{
		int b = 0;
		int e = m_length - 1;

		while( m_str[b] == ' ' ) b++;
		while( m_str[e] == ' ' ) e--;

		if( b == 0 )	//m_str[0] is not ' '
		{
			m_str[e + 1] = '\0';
			m_length = e + 1;
		}
		else
		{
			for(int i=0, j=b; j<=e; i++, j++)
			{
				m_str[i] = m_str[j];
			}

			m_str[e - b + 1] = '\0';
			m_length = e - b + 1;

		}

		return *this;
	}

	char* str()
	{
		return m_str;
	}

	int length()
	{
		return m_length;
	}

	~String()
	{
		free(m_str);
	}
};










#endif