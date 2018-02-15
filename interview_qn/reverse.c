#include "header.h"
int main()
{
	int p =98765;
	int base = p;
  int remain = 0;
  int reverse = 0;
  
	while(base > 0)
	{
	 remain  = base%10;
   base = base /10;
   reverse = (reverse *10)+remain;;
	}
  printf("Reverse = %d", reverse);
	return 0;
}
