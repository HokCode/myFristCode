#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Operator
{
public:
	T add(T a, T b);
	T sub(T a, T b);
	T multify(T a, T b);
	T divide(T a, T b);
};

template <typename T>
T Operator<T>::add(T a, T b)
{
	return (a + b);
}

template <typename T>
T Operator<T>::sub(T a, T b)
{
	return (a - b);
}

template <typename T>
T Operator<T>::multify(T a, T b)
{
	return (a * b);
}

template <typename T>
T Operator<T>::divide(T a, T b)
{
	return (a / b);
}

int main()
{
	Operator<int> op1;
	cout << op1.add(1, 1) << endl;
	cout << op1.sub(1, 1) << endl;
	cout << op1.multify(1, 1) << endl;
	cout << op1.divide(1, 1) << endl;
	
	return 0;
}