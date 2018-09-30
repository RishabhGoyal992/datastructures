#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left ;
    struct node * right ;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node * inserttree(struct node * r ,int val){
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
void inorder(struct node * r){
    if(r){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}
int isidentical(struct node * r1, struct node * r2){
    if(!r1 && !r2){
        return 1;
    }
    if(r1 && r2){
        return((r1->data==r2->data)&&(isidentical(r1->left,r2->left))&&(isidentical(r1->right,r2->right)));
    }
    return 0;
}
int main()
{
    printf("\nenter n1:");
    int n1;
    scanf("%d",&n1);
    printf("\nenter n2:");
    int n2;
    scanf("%d",&n2);
    printf("\nenter the elements of first bst:\n");
    int a[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&a[i]);
    }
    printf("\nenter the elements of second bst:\n");
    int b[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&b[i]);
    }
    struct node * root1 = NULL;
    struct node * root2 = NULL;
    root1=inserttree(root1,a[0]);
    for(int i=1;i<n1;i++){
        inserttree(root1,a[i]);
    }
    root2=inserttree(root2,b[0]);
    for(int i=1;i<n2;i++){
        inserttree(root2,b[i]);
    }
    printf("\n");
    printf("\n");
    inorder(root1);
    printf("\n");
    inorder(root2);
    printf("\n");
    printf("\n");
    if(isidentical(root1,root2)){
        printf("\nboth trees are identical\n");
    }else{
        printf("\ntrees are not identical\n");
    }
    return 0;
}
