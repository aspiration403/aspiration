/*In factory method, we ask for object and factory return the object.
Example: Let's suppose on 14th feb, we need some rose bouquet, we go to folowerist, and we simply ask red rose, he provide us, here we don't intrested that from where he got the rose and it's details.
*/


#include <iostream>
#include <string>
using namespace std;

class IRose
{
  public:
    virtual void color() = 0;
};

class RedRose : public IRose
{
  
  public:
   virtual void color()
   {
      cout<<"I am red color Rose"<<endl;
   }
};

class yellowRose : public IRose
{
  
  public:
   virtual void color()
   {
      cout<<"I am yellow color Rose"<<endl;
   }
};

class factory
{
  IRose* rose;
  public:
    IRose* getObject(string Bouquet);
};

IRose* factory :: getObject(string Bouquet)
{
   if ("red" == Bouquet)
   {
     rose = new RedRose();
   }
   else if ("yellow" == Bouquet)
   {
     rose = new yellowRose();
   }
   else
     rose = NULL;
   
  return rose;
}

int main()
{
  factory *Factory = new factory();
  IRose *Rose;
  Rose = Factory->getObject("red");
  if (NULL != Rose)
  {
     cout<<"Got my Bouquet"<<endl;
     Rose->color();
  
  }
  delete Rose;
 Rose = Factory->getObject("yellow");
  if (NULL != Rose)
  {
     cout<<"Got my Bouquet"<<endl;
     Rose->color();
  
  }
 return 0;
}

