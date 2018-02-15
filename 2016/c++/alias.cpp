#include"header.h"
int main()
{
	//char *ch="Raman Kumar";
	//char & x=ch;
	int sum =20;
	int & x = sum;
	cout<<x;
	x=x+20;
	cout<<sum;
	return 0;
}
