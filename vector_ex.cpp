#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int i = 0;
  std::vector<int> myList;
  for (i = 1; i <= 5; i++)
  {
    myList.push_back(i* 10);
  }

  std::vector<int>::iterator iter = myList.begin();
  
  for (iter = myList.begin(); iter != myList.end(); iter++)
  {
    cout<<"Num: "<<*iter<<endl;
  }

  
  std::vector<int>::iterator iter1 = myList.begin();
  iter1 = iter1 +3; 
  iter = find (myList.begin(), myList.end(),*iter1);
  if (iter != myList.end())
     cout<<"Element found "<<*iter;
  
  return 0;
}

