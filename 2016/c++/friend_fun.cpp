#include<iostream>
using namespace std;

class ABC;
class XYZ
{
	int num1,num2;
	public:
		void getdata(int x,int y)
		{
			num1 = x;
			num2 = y;
		}
		void display_data(void)
		{
			cout<<"\n complex number = "<<num1<<"+j"<<num2;
		}
		friend XYZ addition(XYZ,ABC);
};

class ABC 
{
	int num1,num2;
	public:
		void getdata_A(int x,int y)
		{
			num1 = x;
			num2 = y;
		}

		void display_data_A(void)
		{
			cout<<"\n complex number2 = "<<num1<<"+j"<<num2;
		}

	friend XYZ addition(XYZ,ABC);
};


XYZ addition(XYZ X,ABC A)
{
	XYZ sum;
	sum.num1 = X.num1 + A.num1;
	sum.num2 = X.num2 + A.num2;
	return sum;	
}
int main()
{
	XYZ X,sum;
	ABC A;
	X.getdata(20,3);
	X.display_data();
	A.getdata_A(30,5);
	A.display_data_A();
	sum = addition(X,A);
	sum.display_data();
	return 0;
}
