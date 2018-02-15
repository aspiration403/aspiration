#include <iostream>
using namespace std;

class base
{
  public:
    virtual void printClassName() { cout<<"I am Base";}
};

class derived : public base
{
  int p;
  public:
   void printClassName() {cout<<"I am derived";}
};

int main()
{
  base objBase;
  derived objDerived;
  cout <<"Base Size :"<<sizeof(objBase)<<endl;
  cout <<"Derived Size :"<<sizeof(objDerived)<<endl;
  return 0;
}
