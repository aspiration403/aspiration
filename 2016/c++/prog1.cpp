#include<iostream>
using namespace std;
class person
{
	char name[10];
	int age;
	public:
		void getdata();
		void display();
};

void person::getdata()
{
	cout<<"Enter the name:";
	cin >> name;
	cout <<"\nEnter age :";
	cin >> age;
}
void person::display()
{
	cout<<"\n Name :"<<name<<"\n Age :"<<age;
}
int main()
{
	person p;
	p.getdata();
	p.display();
	return 0;
}
