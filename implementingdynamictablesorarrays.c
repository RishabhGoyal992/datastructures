#include <stdio.h>
#include<stdlib.h>

int main()
{   int size=0;int capacity=1;

    
    printf("\nimplementing dynamic tables\n");
    
  int n;
  printf("\nenter n :\n");
  
  scanf("%d",&n);
  
  int a[n];
  printf("\nenter values\n");
  
  for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
  }
    
    
    int * ptr=( int * )malloc(sizeof(int));
    
    for(int j=0;j<n;j++){
        if(size==capacity){
            capacity=capacity*2;
            ptr=(int *)malloc(2*sizeof(ptr));
            
        }
        size=size+1;
        for(int u=0;u<size;u++){
        ptr[u]=a[u];
        }
        printf("\ncapacity : %d ",capacity);
        printf(" size : %d ",size);
        printf(" elements : ");
        for(int k=0;k<size;k++){
            printf(" %d",ptr[k]); 
        }
        
    }
    
    return 0;
}
