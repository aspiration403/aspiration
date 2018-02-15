#include <iostream>
using namespace std;
class A
{
				int var ;
				static  A *obj;

				A()
				{
								var = 5;
				}

				public:
				void getName()
				{
								cout<<"Class A";
				}

				static A* getObject()
				{
								if (obj == NULL)
												obj = new A;
								return obj;
				}

};

A* A::obj = 0;

int main()
{
				A *objB = A::getObject();
				objB->getName();
				cout <<"Addresss objB :\n"<<objB; 

				A *objC = A::getObject();
				objC->getName();
				cout <<"Addresss objC :\n"<<objC; 

				return 0;
}
