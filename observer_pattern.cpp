/*Distributor Contains the list of all types of shops. Whenever the price of product change,then distributor Notify these change to shops via carecenter.
                                                                            
                                          ##############                                   
                                            Distributor                                   
                                -------->     
                    RateChange            ##############                                   
                   |------------                                 
                   |                                                     | KIRYANA SHOP |              ---- ------  
                   |                                                          ^                        CONFECTIONARY                                                                               |                          ------------
                   |                                                          |             |  MALL  |       ^   
                   |                                               updatePrice|                 ^            |  
                   |                                                          |    updatePrice  |            |
                   |                                          --------------- |                 |            |    
                   |                                             CARE CENTER -------------------             |       
                   |                                                          -------------------------------- 
                                                               ===============                      updatePrice
                   |   
           ------------------     
           |   PRODUCT      |     
           |    RateChange  |
           -------------- ---


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//class careCenter;
/*
 * Shops will directly in touch with care center agent. And  Care-center is in touch with Distibutor, so whenever any update is in distributor , carecenter will pass this info to all shops/confectionary.
 * */
class careCenter
{
  public:
  virtual int updatePrice(float newRate) = 0; 
  virtual void printMilkPrice() = 0;
};
/*
 *  Here Distributor have the information of all shops.in forms of customer care
 * */
class distributor
{
//  int price;
  std::vector<careCenter*> shopList;
  public:
   void subscribe(careCenter* cc);
   void unsubscribe(careCenter* cc);
   void Notify(float price);
   
};

void distributor::subscribe(careCenter *obj)
{
  shopList.push_back(obj);
}

void distributor::unsubscribe(careCenter* obj)
{
  std::vector<careCenter* >::iterator iter;
  iter = find(shopList.begin(), shopList.end(),obj);
  if (iter != shopList.end())
   shopList.erase(iter);
}

void distributor::Notify(float price)
{
  std::vector<careCenter* >::iterator iter;
  for (iter = shopList.begin(); iter != shopList.end(); iter++)
  {
    (*iter)->updatePrice(price);
    
  }

  for (iter = shopList.begin(); iter != shopList.end(); iter++)
  {
    (*iter)->printMilkPrice();
    
  }

}
/*
 * Manufactures is actually providing product and it set's price as per thier benifit.
 * For the time being There is only one manufacturer(to understand singleton concept), it can be normal.
 * when it change the price, it reflects back to distributor. 
 * */
class Manufacturer : public distributor
{
     float price;
     static Manufacturer *company; 
     Manufacturer(float rate)
     {
        this->price = rate;
     }
     public:
     int changePrice(float rate);
     static Manufacturer* getCompany();  
};

Manufacturer* Manufacturer ::company = NULL;

Manufacturer* Manufacturer::getCompany()
{
  if (NULL == company)
  company = new Manufacturer(25);
 
  return company;
}

int Manufacturer::changePrice(float price)
{
  this->price = price;
  Notify(this->price); 
}

class kiryanaShop: public careCenter
{
    float MilkPrice;
    int riceRate;
    string shopName;
    public:
    kiryanaShop(string shop = "ABC",float rate = 40.0)
    {
      shopName = shop;
      MilkPrice = rate;   
      riceRate = 30;
    } 
    int updatePrice(float newRate);
    void printMilkPrice();
};

int kiryanaShop::updatePrice(float newRate)
{
   MilkPrice = newRate;
   return 0;
} 

void kiryanaShop::printMilkPrice()
{
  cout<<"Shop :"<<this->shopName <<"Rate "<<this->MilkPrice<<endl; 
}

class Confectionary : public careCenter
{
    float MilkPrice;
    string shopName;
    int breadRate;
    public:
    Confectionary(string shop = "ABC",float rate = 40.0)
    {
      shopName = shop;
      MilkPrice = rate; 
      breadRate = 35;  
    } 
    int updatePrice(float newRate);
    void printMilkPrice();
};

int Confectionary::updatePrice(float newRate)
{
   MilkPrice = newRate;
   return 0;
} 

void Confectionary::printMilkPrice()
{
  cout<<"Confectionary :"<<this->shopName <<"  MilkRate "<<this->MilkPrice<<endl; 
}

int main()
{
  careCenter *rahulShop = new kiryanaShop("Rahul",25);
  careCenter *roshanShop =  new kiryanaShop("Roshan",35);
  careCenter *raman = new Confectionary("Raman",45);
  careCenter *pankaj = new Confectionary("Pankaj",45);
  Manufacturer *Amul = Manufacturer::getCompany();
  Amul->subscribe(rahulShop);
  Amul->subscribe(roshanShop);
  Amul->subscribe(raman);
  Amul->subscribe(pankaj);
  
  raman->printMilkPrice();  
  
  Amul->changePrice(15.50);
  Amul->unsubscribe(roshanShop);
  Amul->changePrice(20.50);

  return 0;
}
