
#include <stdio.h>
#include <stdlib.h>
int n;
int a[1000];
int q[1000];int front = 0;int rear = 0;
int level = 1;
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
struct node * inserttree(struct node * r , int i){
    if(i<n){
        struct node * temp = newnode(a[i]);
        r = temp;
        r->left = inserttree(r->left,2*i+1);
        r->right = inserttree(r->right,2*i+2);
    }
    return r;
}
void computelevel(struct node * r, int d,int level){
   if(r == NULL){
       return ;
   }
   if(r->data == d){
       printf("\nLevel of %d is %d ",d,level);
   }
   computelevel(r->left,d,level+1);
   computelevel(r->right,d,level+1);
}
int main()
{
    printf("\nGETTING THE LEVEL OF A NODE\n");
    printf("\nenter the number of nodes :");
    scanf("%d",&n);
    printf("\nenter the node values of the trees :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root = inserttree(root,0);
    printf("\nenter the node value whose level you want to compute :");
    int x;
    scanf("%d",&x);
    computelevel(root,x,level);
    return 0;
}
