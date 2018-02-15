#include"header1.h"
struct complex_no
{
	float c1,c2;
	public:
	void add(float a,float b);
//	{
//		cout<<"sum="<<a+b;		
//	}
}num;

void complex_no ::add(float a,float b)
{
	
	
		cout<<"sum="<<a+b;		
	
}

int main()
{
	num.c1=20;
	num.c2=30;
	num.add(num.c1,num.c2);

	return 0;
}
