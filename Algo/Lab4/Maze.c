#include<stdio.h>
void dfs(int v,int v2);
int n,a[10][10];
typedef enum boolean{false,true}bool;
bool visited[10];
int arr[10];
int inex=0;
void main()
{
int i,j,v,v2;
printf("Enter the no. of nodes in the graph\n");
scanf("%d",&n);
printf("Enter the adjacency matrix \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("The adjacency matrix shown as\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
printf("Enter the starting node for the Maze\n");
scanf("%d",&v);
printf("Enter the ending node for the Maze \n");
scanf("%d",&v2);
for(i=1;i<=n;i++)
visited[i]=false;
dfs(v,v2);
}
void dfs(int v,int v2)
{
	int flag=0;
int i,stack[10],top=-1,pop;
top++;
stack[top]=v;
while(top>=0)
{

pop=stack[top];
printf("Popping %d\n",pop);
top--;
if(visited[pop]==false)
{
arr[inex++]=pop;
visited[pop]=true;
}
else
continue;
for(i=n;i>=1;i--)
{
if(a[pop][i]==1 && visited[i]==false)
{
	if(i==v2){
		printf("End of Maze Found  \n");
	flag=1;
	}
  printf("Pushing %d \n",i);
top++;
stack[top]=i;
if(flag==1)
{
	arr[inex++]=v2;
}
break;
}
}
if(flag==1)
break;
}
for(int i=0;i<inex;i++)
{
  printf("%d \t",arr[i]);
}
}
