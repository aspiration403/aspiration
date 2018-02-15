#include<iostream>
using namespace std;

class ABC;
class XYZ
{
	int num1;
	public:
		void getdata(int x)
		{
			num1 = x;
			
		}
		void display_data(void)
		{
			cout<<"\n  number = "<<num1;
		}
		friend void swap(XYZ & , ABC &);
};

class ABC 
{
	int num;
	public:
		void getdata_A(int x)
		{
			num = x;
		}

		void display_data_A(void)
		{
			cout<<"\n  number2 = "<<num;
		}
		friend void swap(XYZ & , ABC &);

};


void swap(XYZ &X,ABC &A)
{
	int temp;
	temp = X.num1;
	X.num1 = A.num ;
	A.num = temp ;
		
}
int main()
{
	XYZ X;
	ABC A;
	X.getdata(20);
	X.display_data();
	A.getdata_A(30);
	A.display_data_A();
	swap(X,A);
	X.display_data();
	A.display_data_A();
	return 0;
}
