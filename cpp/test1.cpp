#include<iostream>
using namespace std;

class B
{
		public :
			void className()
			{
				cout<<"Class B";
			}
};


class A
{
	public:
	static B *objB ;
		static B* getInstance()
		{
			if (NULL == A::objB)
			{
				A::objB = new B;
			}
		  return A::objB;		
		}

};
int main()
{
		B *obj = A::getInstance();
		obj->className();
		return 0;
}



