#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Ball
{
	std::string  m_color;
	float m_rad;
  public:
#if 0
	Ball()
	{
		m_color = "Red";
		m_rad = 20.0;
	} 
#endif     
  Ball(  std::string  color="Red", float rad=10.0)
	{
		m_color = color;
		m_rad = rad;
	}
#if 0      
 Ball( std::string  color)
	{
		m_color = color;
		m_rad = 10.0;
	}
       Ball( float rad)
	{
		m_color = "black";
		m_rad = rad;
	}
#endif
	void print()
	{
		cout<<"color :"<<m_color<<"Radius"<<m_rad;	
	}
};
int main()
{
  string s="jaynat";
	Ball red;
	red.print();
	Ball def(s);
	def.print();
	Ball blue("blue",15);
	blue.print();
	return 0;
}	
