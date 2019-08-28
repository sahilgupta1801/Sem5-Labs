#include <stdio.h>
int euclid(int a, int b)
{

	while (a != b)
	{
		if (a > b)
		   a = a - b;
		else
		   b = b - a; 
	}

	return a;		
}
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b); 

	printf("euclid(%d, %d) = %d", a, b, euclid(a, b));

	return 0;
}
