#include <stdio.h>
#include <stdlib.h>

int a[1000];
struct node {
  int data;
  struct node * left;
  struct node * right;
};

struct node * newnode(int d){
    struct node * newn = (struct node *)malloc(sizeof(struct node));
    newn->data=d;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}

struct node * insertintotree(int a[],struct node * p,int i,int n){
    if(i<n){
        struct node * temp = newnode(a[i]);
        p=temp;
        p->left=insertintotree(a,p->left,2*i+1,n);
        p->right=insertintotree(a,p->right,2*i+2,n);
    }
    return p;
}

void inorder(struct node * root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}

int main()
{
    printf("\n\n\t\tBINARY TREE USING ARRAY\n\n");
    printf("\n\tenter the number of elements to be :\n");
    int n;
    scanf("%d",&n);
    
    printf("\nenter the elements :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root=insertintotree(a,root,0,n);
    printf("\ninorder is \n");
    inorder(root);
    return 0;
}
