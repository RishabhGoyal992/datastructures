#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node * next ;
};
struct node * a[1000];
void enternode(struct node * a[],int i){
    
    while(1){
        printf("\nwant to enter value? 1.yes 2.no\n");
        int c;
        scanf("%d",&c);
        if(c==2){
            return ;
        }
        struct node * nn = (struct node *)malloc(sizeof(struct node));
        printf("\nvalue of connected node to node %d :",i+1);
        int l;
        scanf("%d",&l);
        nn->data =l;
        nn->next = NULL;
        
        if(a[i]==NULL){
            a[i]=nn;
        }else{
        struct node * temp = a[i] ;
        nn->next=temp;
        a[i]=nn;
        }
    }
}
void printnodesconnected(struct node * a[],int i){
    struct node * temp = a[i];
    
    while(temp){
        printf(" node (%d). ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    printf("\nGRAPH IMPLEMENTATION USING ADJACENCY LISTS\n");
    int n ;
    printf("\nnumber of nodes in the graph ? ");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        a[n]=NULL;
    }
    //(*a)[n] is pointer to array where as *a[n] or *(a[n]) is array of pointers
    for(int i=0;i<n;i++){
        printf("\nvalues for %d node?\n",i+1);
        enternode(a,i);
    }
    printf("\n ADJACENCY list representaion of  graph\n");
    for(int i=0;i<n;i++){
    printf("\n node %d -> ",i+1);
    printnodesconnected(a,i);
    }
    return 0;
}
