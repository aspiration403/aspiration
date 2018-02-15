#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
	std::vector<int> vect(2, 40);
	std::list<int> list1(4,30) ;
	std::list<int>::iterator it = list1.begin();
	
  list1.insert(it,vect.begin(),vect.end());
   
  it = list1.begin();
	while(it != list1.end())
	{
		cout<<"Val \n"<<*it;
		it++;
	}

  it = list1.begin();
	list1.push_back(55);
	list1.push_front(10);	
	it = list1.begin();
	while(it != list1.end())
	{
		cout<<"Val \n"<<*it;
		it++;
	}
  int k = list1.pop_back();
	cout<<"K:"<<k;	
	return 0;	
}
