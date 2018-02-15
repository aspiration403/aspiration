/*) Write a program that asks the user to enter their full name and their age. As output, tell the user how many years they’ve lived for each letter in their name (for simplicity, count spaces as a letter)
*/
#include <iostream>
#include <string>
using namespace std;

class Person
{
	
	string name;
	int age;
	public:
		Person()
		{
			name = "";
			age = 0;
		}
		int setData();
		void getData() const;
		int letterAge();
};

int Person::setData()
{
	cout <<"Enter Age :";
	cin>>age;
	std::cin.ignore(32767,'\n');
	cout<<"Enter name :";
	getline(std::cin,name);	
}

void Person::getData() const
{
	cout<<"My Name is :"<<name<<"\n Age :"<<age; 	
}

int Person::letterAge()
{
	int len = name.length();
	float letAge = static_cast<float>(age)/len;
	cout<<"\nAge of each letter :"<<letAge;
	
}
int main()
{
	Person raman;
	raman.setData();
	raman.getData();
	raman.letterAge();
	return 0;
}

