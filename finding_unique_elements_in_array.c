#include <stdio.h>

int main()
{
    int a[]={2,3,1,4,5,6,2,1,8,6,2,9,11,2,13,3,1};
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]<a[j]){
                int temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    int c[1000]={0};
    int k=0;
    for(int i=0;i<n;i++){
        if(c[k]!=a[i]){
            c[++k]=a[i];
        }else{
            continue;
        }
    }
    
    printf("\n");
    for(int i=1;i<k+1;i++){
        printf("%d ",c[i]);
    }
    return 0;
}
