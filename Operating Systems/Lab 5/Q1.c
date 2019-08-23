#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
void* child_thread(int n)
{
	int *arr=(int*)malloc(sizeof(int)*n);
	arr[0]=0;
	arr[1]=1;
	n=n-2;
	int i=2;
	while(n>0)
	{
		arr[i]=arr[i-1]+arr[i-2];
		i++;
		n--;

	}
	return (void*)arr;
}

int main()
{
	int n;
	void* temp;
	printf("Enter Limit \n");
	scanf("%d",&n);
	pthread_t thread;
	int *ret;
	pthread_create(&thread,0,&child_thread,(void*)n);
	pthread_join(thread,&temp);
	ret=temp;
	for(int i=0;i<n;i++)
		printf(" %d \n",ret[i]);
	
}
