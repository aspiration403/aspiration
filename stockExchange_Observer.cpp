#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class shareHolderInterface
{
  public:
   virtual void update(float ) = 0;
   virtual void printShareHolderInfo() = 0; 
};

class JioShareHolder : public shareHolderInterface
{
  string name;
  float JioShareRate;
  public:
  JioShareHolder(string, float);
  void update(float rate);
  void printShareHolderInfo(); 
};

class OilShareHolder : public shareHolderInterface
{
  string name;
  float OilShareRate;
  public:
  OilShareHolder(string, float);
  void update(float rate);
  void printShareHolderInfo(); 
};


class stockExchangeInterface
{
  public:
    virtual int Register(shareHolderInterface* obj) = 0;
    virtual int UnRegister(shareHolderInterface* obj) = 0;
    virtual int Notify(float) = 0;
};

class JioStockExchange : public stockExchangeInterface
{
  float jioBaseRate;
  float newRate;
  ::std::vector< shareHolderInterface *> AllShareHolder;
  public:
   JioStockExchange(float);
   int Register(shareHolderInterface* obj);
   int UnRegister(shareHolderInterface* obj);
   int Notify(float rate);
   
   int setStackRate(float rate);  
   int checkAndNotifyShareHolder();
};

JioStockExchange::JioStockExchange(float baseRate = 50)
{
  jioBaseRate = baseRate;
  newRate = 0.0f;
}

int JioStockExchange::Register(shareHolderInterface* obj)
{
  AllShareHolder.push_back(obj);
}

int JioStockExchange::UnRegister(shareHolderInterface* obj)
{
  ::std::vector< shareHolderInterface* >::iterator iter;
  iter = find(AllShareHolder.begin(), AllShareHolder.end(), obj);
  if ( iter != AllShareHolder.end())
  {
     AllShareHolder.erase(iter);
  }
  return 0;
}

int JioStockExchange::Notify(float rate)
{
  ::std::vector< shareHolderInterface* >::iterator iter;
  for (iter = AllShareHolder.begin(); iter != AllShareHolder.end(); iter++)
  {
     (*iter)->update(rate);
  }

  for (iter = AllShareHolder.begin(); iter != AllShareHolder.end(); iter++)
  {
     (*iter)->printShareHolderInfo();
  }
  return 0;
} 

int JioStockExchange::setStackRate(float rate)
{
  this->newRate = rate;
  this->checkAndNotifyShareHolder();
  return 0; 
}

//Notify ShareHolder when change is only greater than equal to 10%  
int JioStockExchange::checkAndNotifyShareHolder()
{
    float differ = newRate - jioBaseRate;
    bool validChange = false;
    if (differ > 0)
    {
        if (differ > ((float)(jioBaseRate *10)/100))
        {
          validChange = true;
          jioBaseRate = newRate; 
          this->Notify(newRate);
        } 
    }

    if (false == validChange)
    cout<<"No need to inform shareholder\n";
 
   return 0;
}

/*
 * OilStackExchange will contain the stock of oil
 * this is beauty of inheriting stock exchange interface. if any new stock company came in market they simply implement method of stockExchaneInterface and reach to the share holder. 
 */

class OilStockExchange : public stockExchangeInterface
{
  float OilBaseRate;
  float newRate;
  ::std::vector< shareHolderInterface *> AllShareHolder;
  public:
   OilStockExchange(float baseRate);
   int Register(shareHolderInterface* obj);
   int UnRegister(shareHolderInterface* obj);
   int Notify(float rate);
   
   int setStackRate(float rate);  
   int checkAndNotifyShareHolder();
};

OilStockExchange::OilStockExchange(float rate = 500)
{
  OilBaseRate = rate;
  newRate = 0.0;
}

int OilStockExchange::Register(shareHolderInterface* obj)
{
  AllShareHolder.push_back(obj);
}

int OilStockExchange::UnRegister(shareHolderInterface* obj)
{
  ::std::vector< shareHolderInterface* >::iterator iter;
  iter = find(AllShareHolder.begin(), AllShareHolder.end(), obj);
  if ( iter != AllShareHolder.end())
  {
     AllShareHolder.erase(iter);
  }
  return 0;
}


int OilStockExchange::Notify(float rate)
{
  ::std::vector< shareHolderInterface* >::iterator iter;
  for (iter = AllShareHolder.begin(); iter != AllShareHolder.end(); iter++)
  {
     (*iter)->update(rate);
  }
  
  for (iter = AllShareHolder.begin(); iter != AllShareHolder.end(); iter++)
  {
     (*iter)->printShareHolderInfo();
  }
  
  return 0;
} 


int OilStockExchange::setStackRate(float rate)
{
  this->newRate = rate;
  this->checkAndNotifyShareHolder();
  return 0; 
}

//Notify ShareHolder when change is only greater than equal to 10%  
int OilStockExchange::checkAndNotifyShareHolder()
{
    float differ = newRate - OilBaseRate;
    bool validChange = false;
    if (differ > 0)
    {
        if (differ > ((float)(OilBaseRate *10)/100))
        {
          validChange = true;
          OilBaseRate = newRate; 
          this->Notify(newRate);
        } 
    }

    if (false == validChange)
    cout<<"No need to inform shareholder\n";
   return 0;
}

/*********************************************************
 * JIO SHARE HOLDER 
 * ****************************************************/

JioShareHolder::JioShareHolder(string name = "ABC", float rate = 50)
{
  this->name = name;
  JioShareRate = rate;
}

void JioShareHolder::update(float rate)
{
   JioShareRate = rate;
} 


void JioShareHolder::printShareHolderInfo()
{
  cout<<"I am "<<name<<" JIO-SHareHolder, my stock rate ="<<JioShareRate<<endl;
}
/*********************************************************
 * OIL SHARE HOLDER 
 * ****************************************************/

OilShareHolder::OilShareHolder(string name = "ABC", float rate = 500)
{
  this->name = name;
  OilShareRate = rate;
}

void OilShareHolder::update(float rate)
{
   OilShareRate = rate;
} 

void OilShareHolder::printShareHolderInfo()
{
  cout<<"I am "<<name<<" JIO-SHareHolder, my stock rate = "<<OilShareRate<<endl;
}


/*
 *Main method
 */

int main()
{
  JioStockExchange *BombayJioExchange = new JioStockExchange(50.0);
  OilStockExchange *BombayOilExchange= new OilStockExchange(500.0);  
//stockExchangeInterface *BombayJioExchange = new JioStockExchange(50.0);
//stockExchangeInterface *BombayOilExchange = new OilStockExchange(500.0);
  
  OilShareHolder Raman("Raman");
  OilShareHolder Pankaj("Pankaj");
  JioShareHolder Rahul("Rahul");
  JioShareHolder Raushan("Raushan");
  
  BombayJioExchange->Register(&Rahul);
  BombayJioExchange->Register(&Raushan);
  BombayOilExchange->Register(&Raman);
  BombayOilExchange->Register(&Pankaj);

  BombayJioExchange->setStackRate(60);
  
  BombayJioExchange->UnRegister(&Raushan);
  
  BombayJioExchange->setStackRate(70);
  return 0;
}


