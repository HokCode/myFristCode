#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Object
{
protected:
	string mName;
	string mInfo;
public:
	Object()
	{
		mName = "Object";
		mInfo = "";
	}
	string name()
	{
		return mName;
	}
	string info()
	{
		return mInfo;
	}
};

class Point : public Object
{
private:
	int mX;
	int mY;
public:
	Point(int x=0, int y=0)
	{
		ostringstream s;

		mX = x;
		mY = y;
		mName = "Point";

		s << "P:(" << mX << "," << mY << ")";
		mInfo = s.str();
	}
};

class Line : public Object
{
private:
	Point mp1;
	Point mp2;
public:
	Line(Point p1, Point p2)
	{
		ostringstream s;

		mp1 = p1;
		mp2 = p2;
		mName = "Line";

		s << "line:" << mp1.info() << " to " << mp2.info();
		mInfo = s.str();
	}
};

int main()
{
	Point p1(0, 0);
	Point p2(5, 5);

	Line L1(p1, p2);

	cout << p1.info() << endl;
	cout << p2.info() << endl;
	cout << L1.info() << endl;

	return 0;
}