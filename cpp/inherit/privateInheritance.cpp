//Public inheritance refers IS-A RELATIONSHIA
//Private inheritance refers HAS-A Relationship ,which is similar to composition

#include <iostream>
using namespace std;

class ring
{
  public:
    void tinkle()
    {
      cout<<"Tin Tin..!! \a \a";  
    }
};

//Compostion
class Dog
{
  ring d_ring;
  public:
    void tinkle()
    {
      d_ring.tinkle();            //Call forwarding
    }
};

//Same work Via private Inheritance
class BigDog : private ring
{
  public:
  using ring::tinkle;
};

int main()
{
  Dog cdog;
  cdog.tinkle();

  BigDog bdog;
  bdog.tinkle();
  return 0;
}

