#include<iostream>
using namespace std;

template<typename T>
T add (T num1 , T num2)
{
	return num1+num2;
}



#if 0
int add (int num1 , int num2)
{
	return num1+num2;
}

double add (double num1 , double num2)
{
	return num1+num2;
}
#endif

int main()
{
	cout<<add(2,5);
  cout<<add(2.2, 3.4);
	return 0;
}
