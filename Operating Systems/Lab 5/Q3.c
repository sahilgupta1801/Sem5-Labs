#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int average;

int size = 0;
int primesize=0;
void *calcAvg(void *arg){
  int *val_p = (int *) arg;
  int sum = 0;
  printf("Starting %d Ending %d", val_p[0],val_p[1]);
  int prime[val_p[1]-val_p[0]];
  for(int i = val_p[0];i< val_p[1]; i++)
  
    int flag=0;
    for(int j=2;j<i;j++)
    {
      if(j%i==0)
      {
        printf("Inside Break \n");
        flag=1;
        break;
      }
    }
      if(flag==0)
      {
        printf("Adding %d",i);
          prime[primesize++]=i;
      }
      
    }
    return (void*)prime;
}

int main(int argc, char *argv[]){
  int *nums = (int*)malloc((argc - 1)*sizeof(int));
  int i = 1;
  for(i = 1; i < argc ; i++){
    nums[i-1] = atoi(argv[i]);
    size++;
  }
  pthread_t avgThread;
  printf("Here \n");
  pthread_create(&avgThread, NULL, calcAvg, (void*)nums);
void* temp;
  pthread_join(avgThread, &temp);
  int *ret=temp;
  printf("%d \n",primesize);
  for(int i=0;i<primesize;i++)
  {
  printf("%d \n",ret[i]);
  }
  free(nums);

}
