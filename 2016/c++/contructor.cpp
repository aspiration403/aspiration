#include<iostream>
using namespace std;

class student
{
	int mark1,mark2,total;

	public:
		student(void);                          //default consstructor
		student(int a,int b);			//parameterized constructor
		student(student &);			//copy constructor
		void total_marks();
		void display();
		
};

student ::student()
{
	mark1 = 0;
	mark2 = 0;
	total = 0;
}

student ::student(int a,int b)
{
	mark1 = a;
	mark2 = b;
	total = 0;
}

student::student(student &s)
{
	mark1 = s.mark1;
	mark2 = s.mark2;
	total = s.total;
}

void student ::total_marks()
{
	total = mark1 + mark2;
}

void student::display()
{
	cout<<"\nMark_1: "<<mark1<<"\n Mark2 : "<<mark2<<"\n total= : "<<total;
}

int main()
{
	student raman;
	raman.display();
//	student pankaj= student(90,90);
//	pankaj.display();
	student pk(30,50);
	pk.display();
	student amit(pk);
	amit.display();
	amit.total_marks();
	amit.display();
	return 0;

}



