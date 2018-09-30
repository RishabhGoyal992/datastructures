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
    if(val <= r->data){
        r->left = inserttree(r->left,val);
    }else{
        r->right = inserttree(r->right,val);
    }
    return r;
}
int ancestors(struct node * r,int val){
    if(!r){
        return 0;
    }
    if(r->data == val){
        return 1;
    }
    if(ancestors(r->left,val)||ancestors(r->right,val)){
        printf("%d ",r->data);
        return 1;
    }
    return 0;
}
struct node * delter(struct node * r){
    if(!r){
        return r;
    }
    if(r->left == NULL && r->right == NULL){
        
        free(r);
        return NULL;
    }else{
        r->left = delter(r->left);
        r->right = delter(r->right);
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
int main(){
    printf("\nenter n :");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("\nenter the values :");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root = inserttree(root,a[0]);
    for(int i=1;i<n;i++){
        inserttree(root,a[i]);
    }
    inorder(root);
    printf("\nenter the value whose ancesters you want to see");
    int k;
    scanf("%d",&k);
    ancestors(root,k);
    printf("\ndelete all terminal nodes\n");
    root=delter(root);
    inorder(root);
    return 0;
}
