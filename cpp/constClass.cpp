#include <iostream>
using namespace std;
class DOB
{
	int date;
	int mon;
	int year;
	public:
	DOB(int, int ,int);
	void setDob(int dt,int mn,int yr);
	void getDob() const;
		
};

DOB::DOB(int dt = 1,int mn= 1,int yr=2000)
{
	setDob(dt,mn,yr);
}

void DOB::setDob(int d, int m,int y)
{
	date = d;
	mon = m;
	year = y;
}

void DOB::getDob() const
{
	cout<<"DOB:"<<date<<mon<<year;
}

int main()
{
	DOB yourDOB;
	const DOB mydob(5,12,1993);
	mydob.getDob();
  mydob = yourDOB;
	yourDOB.getDob();
	return 0;
}

