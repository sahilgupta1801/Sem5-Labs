#include <stdio.h>
int min=10000;
int arr[15][15];
void printArr(int a[],int n) 
{ 
int cost=0;
    for (int i=0; i<n; i++) 
        cost+= arr[i][a[i]];
    if(cost<min)
    	min=cost;
} 
void heapPermutation(int a[], int size, int n) 
{ 
    if (size == 1) 
    { 
        printArr(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
        if (size%2==1) 
        {
            int temp=a[0];
            a[0]=a[size-1];
            a[size-1]=temp; 
        }
  
        
        else
         {

            int temp=a[i];
            a[i]=a[size-1];
            a[size-1]=temp;
         } 
    } 
} 
int main()
{
	int n;
	printf("Enter number of people and jobs \n");
	scanf("%d",&n);
	
	printf("Enter allotment cost matrrix cost \n");
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	int x[n];
	for(int i=0;i<n;i++)
	{
	x[i]=i;
	}
	heapPermutation(x,n,n);
	printf("Minimum cost is %d \n",min);

}
