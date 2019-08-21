#include <stdio.h>
int min=10000;
int arr[15][15];
void printArr(int a[],int n) 
{ 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d \t",arr[i][j]);
        }
        printf("\n");
    }
int cost=0;
int k=a[0];
    for (int i=0; i<n-1; i++) 
    {
        printf("Ith position is %d Adding %d",i,arr[k][a[i+1]]);
        cost+= arr[k][a[i+1]];
        k=a[i+1];
    }
    cost=cost+arr[k][a[0]];
    printf("Cost %d \n",cost);
    if(cost<min)
        min=cost;
} 

void heapPermutation(int a[], int size, int n) 
{ 
    if (size == 1) 
    { 
        for(int i=0;i<n;i++)
            printf("%d \t",a[i]);
        printf("\n");
        printArr(a, n); 
        return; 
    } 
  
    for (int i=1; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
        if (size%2==1) 
        {
            int temp=a[1];
            a[1]=a[size-1];
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
void costcalc(int a[],int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        int temp=a[0];
        a[0]=a[k];
        a[k]=temp;
        k++;
        heapPermutation(a,n,n);
    }
}

int main()
{
    int n;
    printf("Enter number of cities \n");
    scanf("%d",&n);
    
    printf("Enter travelling matrix cost \n");
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d \t",arr[i][j]);
        }
    }
    int x[n];
    for(int i=0;i<n;i++)
    {
    x[i]=i;
    }
    costcalc(x,n);
    printf("Minimum cost is %d \n",min);

}
