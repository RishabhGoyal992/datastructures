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
        r->left=inserttree(r->left,val);
    }else{
        r->right=inserttree(r->right,val);
    }
    return r;
}
struct node * mirrortree(struct node * r ){
   if(!r){
       return;
   }
   mirrortree(r->left);
   mirrortree(r->right);
   
   struct node * temp = r->left;
   r->left = r->right;
   r->right = temp;
}
void preorder(struct node * p){
    if(p){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
int main()
{
    printf("\nMIRROR OF TREE\n");
    int n;
    printf("enter n :");
    scanf("%d",&n);
    int a[n];
    printf("\nenter the values : ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }struct node * root = NULL;
    root=inserttree(root,a[0]);
    for(int i=1;i<n;i++){
        inserttree(root,a[i]);
    }
    preorder(root);printf("\n\n");
    mirrortree(root);
    preorder(root);
    return 0;
}
