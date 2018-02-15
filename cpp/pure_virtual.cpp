#include <iostream>
using namespace std;
class A{
	public:
       		virtual void print() = 0;
};

class B :  public A
{
        int num;
        public:
        void print();
        void printA()
        { 
 		cout<<"class B";
        }  
};

void B:: print()
{
  cout<<"Definition of A";
}
int main()
{
	A *obj = new B;
   //     B objb;
     //   obj = &objb;
        obj->print();    
        //obj->printA();    
        return 0;
}

