#include<iostream>
using namespace std;
int main()
{
	char const *ch ;     //pointer to constant 
	char ch1[10]="Pankaj";	
	char ch2[10]="Raman";
	char *ch3;
	
	ch=ch1;   //we cannot modify address of constant pointer
	cout<<ch<<"\t address :\n"<<&ch;
	ch = ch2;
	
	cout<<ch<<" address :\n"<<&ch;
	
}
