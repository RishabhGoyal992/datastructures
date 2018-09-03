#include <stdio.h>
#include<stdlib.h>
int s=0;int c=0;
int a[1000];
void pop_back(){
    
    s=s-1;
    
    if(s<=(c/4)){
        c=c/2;
        int * a=(int *)malloc((1/2)*sizeof(a));
    }
    
    printf("\ncapacity : %d ;",c);
    printf(" size : %d ;",s);
    printf(" elements : ");
    for(int i=0;i<s;i++){
        printf(" %d",a[i]);
    }
    
}

int main()
{
    printf("\nimplementing pop back in dynamic tables\n");

    
    
    printf("\nenter capacity :\n");
    
    scanf("%d",&c);
    printf("\nenter size : \n");
    scanf("%d",&s);
    
    printf("\nenter values\n");
    
    for(int i=0;i<s;i++){
        scanf("%d",&a[i]);
    }
    
    printf("\nenter number of pop back calls : \n");
    int n;
    scanf("%d",&n);
    while(n--){
        pop_back();
    }
    
    return 0;
}
