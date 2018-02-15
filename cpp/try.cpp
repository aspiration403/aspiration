#include <iostream>
using namespace std;

class base
{

	public:
		base();
		~base();
		
		base(int val);
		void NotifyAlarm();
	private:
		int *base_ptr;
};

class A :public base
{
public:
	  ~A();
		
		A(int var);
		virtual void funA();
		virtual void funB();
	private:
		int *ptr;

};

class B : public A
{
	public:
		B(int y): A(int y){}
		~B();
		void func();

};


base :: ~base()
{
	delete base_ptr;
}

base :: base(int val)
{
	base_ptr = new int;
	*base_ptr = val;
}

A :: A( int x)
{
	ptr = new int;
  *ptr = x;
}

A :: ~A()
{
	delete ptr;
}

B :: ~B()
{
}

void B:: func()
{
	cout<<"I am class B"<<endl;
}

int main()
{

	int var,
      val;
	
	cout<<"enter the var"<<endl;
	cin>>var;

	B obj(var);

	return 0;
}

