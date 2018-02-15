//When we want only one object for work, then we use singlton class
//For any country there can be only one president at a time
#include <iostream>
#include <string>
using namespace std;

class President
{
  string name;
  int salary;
  static President *myPresident;
  
  President()
  {
    name = "Ramnath Kovind";
    salary = 100000; 
  }
  public:
  static President* requestPresident();
  void getPresidentInfo();
  void setPresidentInfo( string name, int renum); 
};

President* President::myPresident = NULL;

President* President::requestPresident()
{
   if (NULL == myPresident)
   {
      myPresident = new President();
       
   }
   return myPresident;
}

void President::getPresidentInfo()
{
  cout<<"My Respected president :"<<name<<" get salary :"<<salary<<endl;
}


void President::setPresidentInfo(string name, int renum)
{
//  this->name = name;
//  this->salary = renum;
//  cout<<"My Respected president :"<<name<<" get salary :"<<salary<<endl;

}


#if 1
class state
{
  string name;
  int population;
  President *activePresident;
  public:
  state()
  {
    name = "";
    population = 0;
    activePresident = President::requestPresident();
  
  } 
  void getStateInfo();
  void setStateInfo(string statename, int population); 
};

void state::getStateInfo()
{
  cout<<"My state :"<<name<<" Population :"<<population<<endl;

  this->activePresident->getPresidentInfo();
}

void state::setStateInfo(string yourState, int population)
{
  this->name = yourState;
  this->population = population;
  
}
#endif
int main()
{
 state bihar;
 bihar.setStateInfo("bihar",20000);   

 state kerla;
 kerla.setStateInfo("kerla",10000);   
 
 bihar.getStateInfo();
 kerla.getStateInfo();

 return 0;
}
