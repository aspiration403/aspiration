//Using friend function we can access the private member of a class.
//Friend function is not the member of a class, even if it is defined inside class definition of a class.

#include <iostream>
using namespace std;
class base
{
	int baseNum;
	public:
		base()
		{
			baseNum = 20;
		}

	friend int printData(base obj);

};

int printData(base obj)
{
  return obj.baseNum;
}

class derived
{
	int num;
    class base objBase;
  public:
    derived()
    {
      num = printData(objBase);
    }
    void showData()
    {
      cout<<"num = "<<num;
    }
};

main()
{
	derived der;
  der.showData();
	return 0;
}
