#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
    int height;
};
struct node * newnode(int val){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    nn->height = 1;
    return nn;
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int height(struct node * r){
    if(r==NULL){
        return 0;
    }else{
        return r->height;
    }
}
int getbalfactor(struct node * r){
    if(r==NULL){
        return 0;
    }else{
        return (height(r->left)-height(r->right));
    }
}
struct node * leftrotate(struct node * x){
    struct node * y = x->right;
    struct node * t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
struct node * rightrotate(struct node * y){
    struct node * x = y->left;
    struct node * t2 = x->right;
    x->right = y;
    y->left = t2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return x;
}
struct node * inserttree(struct node * r,int key){
    if(r==NULL){
        return newnode(key);
    }
    if(key<r->data){
        r->left = inserttree(r->left,key);
    }
    else if(key>r->data){
        r->right = inserttree(r->right,key);
    }else{
        return r;
    }
    r->height = max(height(r->left),height(r->right))+1;
    int balence = getbalfactor(r);
    
    //four cases 
    
    if(balence>1 && key< r->left->data){
        return rightrotate(r);
    }
    if(balence<-1 && key > r->right->data){
        return leftrotate(r);
    }
    if(balence>1 && key>r->left->data){
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }
    if(balence<-1 && key<r->right->data){
        r->right = rightrotate(r->right);
        return leftrotate(r);
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
int main(){
    printf("\nenter n : ");
    int n;
    struct node * root = NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nenter the key : ");
        int k;
        scanf("%d",&k);
        root = inserttree(root,k);
    }
    preorder(root);
    return 0;
}
