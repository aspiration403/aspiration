#include <iostream>
using namespace std;
class A
{
	int len;
	int wid;
	public:
#if 0
		A(int l =3 , int w = 5)
		{
			len = l;
			wid = w;
			cout<<"len="<<len<<"wid"<<wid<<endl;	
		}	
#endif
//This is called constructor initialization
#if 0
		A():len(3),wid(5)
		{
			cout<<"len="<<len<<"wid"<<wid<<endl;	
		}     
#endif
		A(int l=4,int w =5):len(l),wid(w)
				{
								//		cout<<"len="<<len<<"wid"<<wid<<endl;	
				}     
		void printA()
		{
						cout<<"len="<<len<<"wid"<<wid<<endl;	
		}	
};
class B 
{
				int area;
				int peri;
				public:
				A objA;   
				B(int ar =3 , int pr = 5)
				{
								peri = pr;
								area = ar;
								//	cout<<"area="<<area<<"wid"<<peri<<endl;

				}	
    void printB()
		{
			cout<<"area="<<area<<"wid"<<peri<<endl;	
		}
                	
};
int main()
{
				class B objb(5,10);
				objb.printB();
				// objb.area = 20;
				objb.objA.printA(); 

				return 0;
}

