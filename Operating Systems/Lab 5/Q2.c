#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int average;

int size = 0;

void *calcAvg(void *arg){
  int *val_p = (int *) arg;
  int sum = 0;
  int i = 0;
  for( i = 0; i < size; i++){
    if(val_p[i]>0)
    	sum=sum+val_p[i];
      }
      return (void*)sum;
}

int main(int argc, char *argv[]){
  int *nums = (int*)malloc((argc - 1)*sizeof(int));
  int i = 1;
  for(i = 1; i < argc ; i++){
    nums[i-1] = atoi(argv[i]);
    size++;
  }
  pthread_t avgThread;

  pthread_create(&avgThread, NULL, calcAvg, (void*)nums);
void* temp;
  pthread_join(avgThread, &temp);
  int *ret=temp;
  printf("Sum = %d \n",ret);
  free(nums);

}
