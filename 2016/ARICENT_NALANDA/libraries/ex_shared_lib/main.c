#include<stdio.h>
#include<add.h>
#include<sub.h>
/**need to give declaration of library function otherwise it thorow error or wrong output*/
//float add(float a, float b);
//float sub(float a, float b);

int main()
{
	float sum;
	float remain;
	printf("\n in main ");
	
	sum = add(5,15);
	printf("sum :%f :",sum);
	remain = sub(5,15);
	printf("sub :%f :",remain);
	return 0;
	
}
