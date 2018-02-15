#include <iostream>
#include <list>
using namespace std;

int main()
{
  list<int> myList1 = {1,2,3,4,5,6,7};
  list<int>mylist2 = {10,20,30};
  /*
  list<int>::iterator it;
  it = mylist2.begin();
  ++it;
  mylist2.splice(it, mylist1);
  */
  for (list<int>::iterator iter;  iter != mylist2.end(); iter++)
  {
    cout<<*iter<<" ";
  }  
  return 0;
}
