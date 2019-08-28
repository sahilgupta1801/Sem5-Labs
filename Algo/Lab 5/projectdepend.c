	
#include <stdio.h>
 
int main(){
	int i,j,k,n,a[10][10],indeg[10],flag[10],count=0;
 
	printf("Enter the no of projects:\n");
	scanf("%d",&n);
 
	printf("Enter the dependency in the form of adjacency matrix:\n");
	for(i=0;i<n;i++){
		printf("Enter row %d\n",i+1);
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
 
	for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
 
    printf("\nThe order of performing tasks is :");
    int check;
    while(count<n){
        for(k=0;k<n;k++){
            if((indeg[k]==0) && (flag[k]==0)){
                check=k;
                printf("%d ",(k+1));
                flag [k]=1;
            }
 
            for(i=0;i<n;i++){
                if(a[check][i]==1)
                {
                    a[check][i]=0;
                    indeg[i]--;
                }
            }
        }
 
        count++;
    }
 
    return 0;
}
