#include"header.h"
class item
{
	static int count;
	int price;
	public:
		void  display(void);
		void getprice(int p )
		{
			price = p;
			count++;
		}
		//void avrage();
	/*	{
			cout<<"count :"<<count;
		//	cout<<"Avg price="<<average;
		}*/
};

int item :: count;
void item ::dispaly(void)
{
			cout<<"count :"<<count;
//	 average = price/count;
} 

int main()
{
	item u1,u2,u3,a;
/*	cout<<"count="<<u1.display();
	cout<<"count="<<u2.display();
	cout<<"count="<<u3.display();
*/	u1.getprice(20);
	u2.getprice(30);
	u3.getprice(40);
	cout<<a.display();
/*	cout<<"count="<<u1.display();
	cout<<"count="<<u2.display();
	cout<<"count="<<u3.display();
*/	
	return 0;
}
