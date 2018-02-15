#include<iostream>
using namespace std;

class base
{
  public:
    void printPublic() { cout<<"I am public function of base \n";}
  protected:
    void printProtected() { cout<<"I am protected function of base\n";}
  private:
    void printPrivate() { cout<<"I am private function of base\n";}
};

class derive_pub : public base
{
  public:
   using base::printProtected;
   void print()
    {
     cout<<"I am class derive_pub\n";
     printProtected();
   }
};

class derive_prot :  protected base
{
  
  public: 
   using base::printPublic;
   void print()
   {
     cout<<"I am class derive_prot\n";
     printPublic();    //ok
     printProtected();  //ok
//     printPrivate();    //Error
   
   }
   
};

class derive_priv : private base
{
   public: 
   void print()
   {
     cout<<"I am class derive_private\n";
       
   }
};

int main()
{
  derive_pub obj;
  obj.printPublic();       //ok it works fine
  obj.printProtected();    //Error :we can't acess protected function outside , to acess in class we need to declare                                this function in derive_pub class  
//  obj.printPrivate();      //Can't access private member otside the class
 

#if 0
  obj.print();                //It works fine
  
  derive_prot obj1;
  obj1.printPublic();     //OK
//  obj1.printProtected();       //Error---->to remove need to write declareation in class derive_prot
   
  base* bp = &obj;
  bp->printPublic();

  bp = &obj1; 
#endif
  return 0;
}




