#include <iostream>
class add {
	int a ;

	private:
	int b ;	
	void print()
	{
					std::cout<<"I am printing from class add";
					std::cout << a;
	}	
	add(int av, int bv){
					a=av;
					b=bv;          
					std::cout<<"I am printing from class add"<<a;
	}
	public:
	add()
	{
					a = 0;
					b = 0;
	}

};

class diff {
	int c;
	int d;
	};
#if 0
	public:
		void print()
		{
			std::cout<<"I am printing from class add";
		}
	}
#endif


int main()
{
//	class add obj(2,4);
	class add obj;
//	class diff obj1;
//	obj1.print();
 //    cout << obj.a;
//     std::cout << obj.a;
//       std::cout<<obj.b;
// obj.print(); 	
	return 0;
}

