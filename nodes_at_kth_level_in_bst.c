#include<stdio.h>
#include<stdlib.h>
struct node{
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
    if(val<=r->data){
        r->left = inserttree(r->left,val);
    }else{
        r->right = inserttree(r->right,val);
    }
    return r;
}
void kthnode(struct node * r,int k){
    if(r){
        if(k==0){
        printf("%d ",r->data);
        return ;
    }
    --k;
    kthnode(r->left,k);
    kthnode(r->right,k);
    }
}
int main(){
    printf("\nenter n :");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("\nenter the values :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the values of k :");
    int k ;
    scanf("%d",&k);
    struct node * root = NULL;
    root = inserttree(root,a[0]);
    for(int i=1;i<n;i++){
        inserttree(root,a[i]);
    }
    printf("\n%d level nodes are : ",k);
    kthnode(root,k);
    return 0 ;
}
