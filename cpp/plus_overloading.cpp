#include <iostream>
using namespace std;
class Length
{
	int m_feet;
	int m_inch;
	public:
	Length(int feet = 0, int inch = 0):m_feet(feet),m_inch(inch){}

	Length operator+(const Length& obj);
	friend std::ostream&  operator<<(std::ostream& out, const Length& lenObj);
};



Length Length::operator+(const Length& obj)
{
	Length total ;
	total.m_feet = this->m_feet + obj.m_feet;
	total.m_inch = this->m_inch + obj.m_inch;
        if (total.m_inch >= 12)
	{
		int feet = (total.m_inch)/12;
		int inch = (total.m_inch)%12;
		total.m_feet = total.m_feet+feet;
		total.m_inch = inch;
	}
	return(total);
}
std::ostream& operator<<(std::ostream& out, const Length& obj)
{
	out<<obj.m_feet<<"Feet"<<obj.m_inch<<"inch";
	return out;
}

int main()
{
	Length len1(20,5);
	Length len2(5,15);
	Length total = len1 + len2;
//	cout<<"total cent:"<<total.getLength();
	cout<<total;	
	return 0;			
} 
