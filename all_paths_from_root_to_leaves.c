#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node * left;
  struct node * right;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node * inserttree(struct node * r,int val){
    if(!r){
        return newnode(val);
    }
    if(val <= r->data){
        r->left = inserttree(r->left,val);
    }else{
        r->right = inserttree(r->right,val);
    }
    return r;
}
void preorder(struct node * r){
    if(r){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
void printallpaths(struct node * r,int b[],int pointer){
    if(!r){
      return ;
    }
    b[pointer++]=r->data ;
    if(r->left==NULL && r->right==NULL){
        printf("\n") ;
        for(int i=0;i<pointer;i++){
            printf("%d ",b[i]) ;
        }
        printf("\n") ;
    }else{
        printallpaths(r->left,b,pointer) ;
        printallpaths(r->right,b,pointer) ;
    }
}
int main()
{
    printf("\nenter n :") ;
    int n ;
    scanf("%d",&n) ;
    int a[n] ;
    printf("\nenter the node values : ") ;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]) ;
    }
    struct node * root = NULL ;
    root=inserttree(root,a[0]) ;
    for(int i=1;i<n;i++){
        inserttree(root,a[i]) ;
    }
    printf("\n\npreorder :\n") ;
    preorder(root) ;
    printf("\n\n") ;
    int b[1000] ;
    int pointer = 0 ;
    printallpaths(root,b,pointer) ;
    return 0 ;
}
