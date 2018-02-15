#include <iostream>
using namespace std;
class A
{
  public :
        int myVal ;
        A()
        {
          myVal = 20;
        }  
	virtual void print()
        {
           cout<<"Class A\n";
        }
};

class B : virtual public A
{
  public :
	void print()
        {
           cout<<"Class B\n";
        }
};
class C : virtual public A,public B
{
  public :
	void print()
        {
           cout<<"Class C\n";
        }
};
int main()
{
	A *obj = new A;
        A obja;
        B objb;
        C objc;
        obj->print();      
        obj = &objb; 
        obj->print();      
        obj = &objc; 
        obj->print();  
        obj->myVal = 30;
        obj = &obja; 
        obj->print();  
        cout<<obj->myVal;   
	return 0;
}
