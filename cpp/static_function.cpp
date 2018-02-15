#include <iostream>
using namespace std;
class measure
{
	int len;
  static int wid ;
	public:
		static int getArea();
		int setLen(int length)
		{
			len = length;	
		}
		int getLength()
		{
			return len;
		}
		void changePara(class measure &meas)
		{
			meas.len = 30;
		}
};

int measure::wid =1;

int measure::getArea()
{
	return wid;
}

int main()
{
//	cout<<"Width :"<<measure::getArea();
	class measure obj1;
	class measure obj2;
	obj1.setLen(10);
	obj1.changePara(obj2);	
	cout<<"Width :"<<obj1.getLength();
	cout<<"Width :"<<obj2.getLength();
  cout <<"Width :"<<measure::getArea();
	cout<<"Width :"<<obj1.getArea();
}

