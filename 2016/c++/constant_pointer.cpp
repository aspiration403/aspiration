#include<iostream>
using namespace std;
int main()
{
	char *const ch="Raman";  //constant pointer
	char ch1[10]="Pankaj";	
	cout<<ch;
	ch=ch1;   //we cannot modify address of constant pointer
	cout<<ch;
	
}
