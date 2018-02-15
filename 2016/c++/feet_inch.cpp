#include<iostream>
using namespace std;
class length
{
	int feet,inch;
	public:
		void getdata(int f, int i)
		{
			feet = f;	
			inch = i;
		}
		void displaydata(void)
		{
			cout<<"\nfeet :"<<feet;
			cout<<"\t Inch:"<<inch;
		}
		void total_length(length,length);
};

void length ::total_length(length l1,length l2)
{
	inch = l1.inch + l2.inch;
	feet = inch/12;
	inch = inch%12;
	feet = feet +l1.feet + l2.feet;	
}
int main()
{
	length l1,l2,l3;
	l1.getdata(5,6);
	l2.getdata(3,7);
	l1.displaydata();
	l2.displaydata();
	l3.total_length(l1,l2);
	l3.displaydata();

	return 0;
}
