#include <iostream>
using namespace std;

class shape
{
  char *name ;
  public:
   
    shape( const char *objName )
    {
       name = objName;
    }
    void getName ()
    {
      cout <<"Name :"<<name;
    }
};

class rectangle : public shape
{
	int length;
  int width;
  public:
  rectangle(int len = 0, int wid = 0)
  {
		length = len;
    width = wid;
    shape("Rectangle");
  }
};

int main()
{
  rectangle rect(20,30);
  rect.getName();

	return 0;
}
