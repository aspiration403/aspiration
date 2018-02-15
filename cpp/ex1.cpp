#include <iostream>
using namespace std;
class Cents
{
	int cents;
	public:
	Cents(int cent=1):cents(cent){}
	friend int getCents(class Cents& obj);
	int setCents(int cent)
	{
		cents = cent;
	}
};

int getCents(class Cents& obj)
{
	return obj.cents;
}

int main()
{
	Cents mycent;
	int retVal = getCents(mycent);
	cout<<"Mycent is :"<<retVal;
	return 0;
	
}

