#include<stdio.h>
#include<add.h>
#include<sub.h>
/**need to give declaration of library function otherwise it thorow error or wrong output*/
float add(float a, float b);
float sub(float a, float b);

int main()
{
	float sum;
	printf("\n in main ");
	
	sum = add(5,15);
	printf("sum :%f :",sum);
	return 0;
	
}
