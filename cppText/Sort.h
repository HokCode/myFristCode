#ifndef _SORT_H_
#define _SORT_H_


class Sort
{
protected:
	Sort();
	Sort(const Sort& e);
	Sort& operator = (const Sort& e);

	template < typename T >
	static void merge(T src[], T* helper, int begin, int mid, int end, bool min2max)
	{
		int i = begin;
		int j = mid + 1;
		int k = begin;
		while((i <= mid) && (j <= end))
		{
			if(min2max ? (src[i] < src[j]) : (src[i] > src[j]))
			{
				helper[k++] = src[i++];
			}
			else
			{
				helper[k++] = src[j++];
			}
		}

		while( i <= mid )
		{
			helper[k++] = src[i++];
		}
		while( j <= end )
		{
			helper[k++] = src[j++];
		}

		for(int i=begin; i<=end; i++)
		{
			src[i] = helper[i];
		}
	}

	template < typename T >
	static void merge(T src[], T* helper, int begin, int end, bool min2max)
	{
		if(begin < end)
		{
			int mid = (begin + end) / 2;

			merge(src, helper, begin, mid, min2max);
			merge(src, helper, mid+1, end, min2max);
			merge(src, helper, begin, mid, end, min2max);
		}
	}

	template < typename T >
	static int partition(T src[], int begin, int end, bool min2max)
	{
		T pc = src[begin];

		while( begin < end )
		{
			while( (begin < end) && (min2max ? (src[end] > pc) : (src[end] < pc)) )
			{
				end--;
			}

			Swap(src[begin], src[end]);

			while( (begin < end) && (min2max ? (src[begin] <= pc) : (src[begin] >= pc)) )
			{
				begin++;
			}

			Swap(src[begin], src[end]);
		}

		return begin;
	}

	template < typename T >
	static void Quick(T array[], int begin, int end, bool min2max)
	{
		if(begin < end)
		{
			int p = partition(array ,begin, end, min2max);
			Quick(array ,begin, p-1, min2max);
			Quick(array ,p+1, end, min2max);
		}
	}

public:
	template < typename T >
	static void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template < typename T >
	static T* Select(T array[], int len, bool min2max = true)
	{
		for(int i=0; i<len; i++)
		{
			int min = i;
			for(int j=i+1; j<len; j++)
			{
				if( min2max ? (array[min] > array[j]) : (array[min] < array[j]) )
				{
					min = j;
				}
			}

			if( min != i )
			{
				Swap<T>(array[min], array[i]);
			}
		}
	}

	template < typename T >
	static T* insert(T array[], int len, bool min2max = true)
	{
		for(int i=1; i<len; i++)
		{
			T e = array[i];
			int k = i;

			for(int j=i-1; j>=0 && (min2max ? (e < array[j]) : (e > array[j])); j--)
			{
				array[j + 1] = array[j];
				k = j;

			}

			if( k != i )
			{
				array[k] = e;
			}
		}
	}

	template < typename T >
	static T* Bobble(T array[], int len, bool min2max = true)
	{
		bool sign = true;
		for(int i=0; i<len && sign; i++)
		{
			for(int j=len-1; j>i; j--)
			{
				sign = false;
				if( min2max ? (array[j] < array[j-1]) : array[j] > array[j-1] )
				{
					Swap(array[j], array[j-1]);
					sign = true;
				}
			}
		}
	}

	template < typename T >
	static T* shell(T array[], int len, bool min2max = true)
	{
		int d = len;

		do
		{
			d = d / 3 + 1;	//希尔发现的数据
			for(int i=d; i<len; i+=d)
			{
				int k = i;
				T e = array[k];

				for(int j=i-d; j>=0 && (min2max ? (array[j] > e) : (array[j] < e)); j-=d)
				{
					array[j + d] = array[j];
					k = j;
				}

				if( k != i)
				{
					array[k] = e; 
				}
			}
		}
		while( d > 1 );
	}

	template < typename T >
	static T* shell_1(T array[], int len, bool min2max = true)	//不用插入实现，用冒泡实现
	{
		int d = len;
		do
		{
			bool sign = true;
			d = d / 3 + 1;
			for(int i=0; i<len && sign; i += d)
			{
				sign = false;
				for(int j=len-1; j>i; j -= d)
				{
					if( min2max ? (array[j] < array[j - d]) : (array[j] > array[j - d]) )
					{
						Swap(array[j], array[j - d]);
						sign = true;
					}
				}
			}
		}
		while( d > 1 );
	}

	template < typename T >
	static T* Merge(T array[], int len, bool min2max = true)
	{
		T* helper = new T[len];
		if( helper != NULL)
		{
			merge(array, helper, 0, len-1, min2max);
		}

		return array;
	}

	template < typename T >
	static T* Quick(T array[], int len, bool min2max = true)
	{
		Quick(array, 0, len-1, min2max);
	}
};

















#endif