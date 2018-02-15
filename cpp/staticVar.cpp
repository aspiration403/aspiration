#include <iostream>	
#include <string>
using namespace std;
class StVar
{
	int value;
	static int num;
	public:
	static int pub_var;
	StVar()
        {
         value=++num; 
	}
         int getVal()
	{
		return value;
	}		
};	

 int StVar::num= 0;
 int StVar::pub_var= 3;


int main()
{
	StVar obj;
	StVar obj1;
	StVar obj2;
	
			
	cout<<"value of static pub_var :"<<StVar::pub_var;
	obj2.pub_var = 6;
	cout<<"value of static val :"<<obj.getVal()<<"\n";
	cout<<"value of static val :"<<obj1.getVal()<<"\n";
	cout<<"value of static val :"<<obj2.getVal()<<"\n";
	cout<<"value of static obj3.pub_var :"<<StVar::pub_var;

	return 0;
}

