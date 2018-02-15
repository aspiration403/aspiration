#include <iostream>
using namespace std;
class Cents
{
	int m_cents;
	public:
	Cents(int num_cent = 0) {m_cents = num_cent;}
	Cents operator+(const Cents& obj);
	int getCents()
	{
		return m_cents;
	}
};
Cents Cents::operator+(const Cents& obj)
{
	return(Cents(this->m_cents + obj.m_cents));
}

int main()
{
	Cents myCent(20);
	Cents yrcent(30);
	Cents total = myCent + yrcent;
	cout<<"total cent:"<<total.getCents();
		
			
} 
