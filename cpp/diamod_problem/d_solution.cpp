#include <iostream>
using namespace std;
/***********************************************************************************************************
class storable //this is the our base class inherited by transmitter and receiver classes
{
        public:
        storable(const char*);
        virtual void read();
        virtual void write(); 
        virtual ~storable();
        private:
        ....
}

class transmitter: public storable 
{
        public:
        void write();
        ...
} 

class receiver: public storable
{
        public:
        void read();
        ...
}

class radio: public transmitter, public receiver
{
        public:
        void read();
        ....
}
*******************************************************/
/**********************************************************************************
Since both transmitter and receiver classes are using the method write() from the base class, 
when calling the method write() from a radio object the call is ambiguous; the compiler can't know 
which implementation of write() to use, the one from the transmitter class or the one from the receiver class.

To understand how this is works, let's take a look at how the objects are represented in memory.
 Inheritance simply puts the implementation of two objects one after another, but in this case radio 
is both a transmitter and a receiver, so the storable class gets duplicated inside the radio object. 
The g++ compiler will complain when compiling the code: error: 'request for member "write" is ambiguous',
 because it can't figure out whether to call the method write() from storable::receiver::radio or from
 storable::transmitter::radio.

Fortunately, C++ allows us to solve this problem by using virtual inheritance. In order to prevent the 
compiler from giving an error we use the keyword virtual when we inherit from the base class storable in
 both derived classes:
****************************************************************************/

class storable //this is the our base class inherited by transmitter and receiver classes
{
        public:
        storable(const char*);
        virtual void read();
        virtual void write(); 
        virtual ~storable();
         
};

class transmitter: public virtual storable 
{
        public:
        void write();
        transmitter()
        {
          cout<<"I am Tx"<<endl;
        }
};

class receiver: public virtual storable
{
        public:
        void read();
        receiver(const char *name);
};

class radio: public transmitter, public receiver
{
        public:
    //    void read();                //when we cal  write compiler gets confused, from which class it should call
        radio(const char *name);
};

storable::storable(const char *name)
{
  cout<<"I am storable class Named : "<<name<<endl;
}
#if 0
transmitter::transmitter(const char *name)
{
  cout<<"I am transmitter class "<<endl;
}


receiver::receiver(const char *name):storable(name) 
{
  cout<<"I am receiver class "<<endl;
}
#endif
radio::radio(const char *name):storable(name),transmitter(),receiver()
{
  cout<<"I am radio class"<<endl;
}

void storable:: read()
{
  cout<<"I am storable read"<<endl;
}

void storable:: write()
{
  cout<<"I am storable write"<<endl;
}

void transmitter::write()
{
  cout<<"I am transmitter write"<<endl;
}

void receiver::read()
{
  cout<<"I am receiver read"<<endl;
}

int main()
{
  radio *rad = new radio("Fm Gold");
  rad->read();
  return 0;
}














 
