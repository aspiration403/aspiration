#include <iostream>
using namespace std;
class A
{
	public:
		virtual int getData() = 0;
		virtual void setData() = 0;	
};


class B :public A
{
	public :
		virtual int getData() ;
		virtual void setData();	
    void name();
};

int B::getData()
{
	cout<<"I am class B";
}

void B::setData()
{
}
void B::name()
{
	cout<<"I am class A";
}

int main()
{
	B *obj = new B;
  obj->name();
	return 0;
}
