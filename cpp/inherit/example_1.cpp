#include <iostream>
using namespace std;

class base
{
  protected:
 // public:
    int var1;
    int var2; 
  public:
    void getInput();
    int addData()
    {
       return var1 + var2;
    }
};

void base::getInput()
{
  cout<<"Enter the Data :";
  cin>>var1>>var2;
}


class derived : public base
{
  public:
   using base::var1;
    void showData() 
    {
       cout<<"Derived class";
    }
};
#if 0
class derived2 : public derived
{
  public:
    void showData2() 
    {
       cout<<"Derived2 class";
    }
};
#endif

int main()
{
  derived obj;
  obj.getInput();
  obj.var1 = 30;
  return 0;
}
