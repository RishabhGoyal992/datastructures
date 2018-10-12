#include<stdio.h>
#include<stdio.h>
struct node{
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
    if(!r){
        return 0;
    }else{
        return r->height;
    }
}
int balencefactor(struct node * r){
    if(!r){
        return 0;
    }else{
        return height(r->left)-height(r->right);
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
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return x;
}
struct node * insertavl(struct node *r,int val){
    if(!r){
        return newnode(val);
    }
    if(val < r->data){
        r->left = insertavl(r->left,val);
    }else if(val > r->data){
        r->right = insertavl(r->right,val);
    }else{
        return r;
    }
    r->height = max(height(r->left),height(r->right))+1;
    int bal = balencefactor(r);
    if(bal>1 && val < r->left->data){
        return rightrotate(r);
    }
    if(bal>1 && val > r->left->data){
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }
    if(bal<-1 && val > r->right->data){
        return leftrotate(r);
    }
    if(bal<-1 && val < r->right->data){
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
struct node * minnode(struct node * r){
    while(r->left){
        r=r->left;
    }
    return r;
}
struct node * delnode(struct node * r , int val){
    if(!r){
        return NULL;
    }
    if(val < r->data){
        r->left = delnode(r->left,val);
    }else if(val > r->data){
        r->right = delnode(r->right,val);
    }else{
        if(r->left==NULL){
            struct node * temp = r->right;
            free(r);
            return temp;
        }
        if(r->right==NULL){
            struct node * temp = r->left;
            free(r);
            return temp;
        }
        struct node * t = minnode(r->right);
        r->data = t->data;
        r->right = delnode(r->right,t->data);
    }
    if(!r){
        return NULL;
    }
    r->height = max(height(r->left),height(r->right))+1;
    int bal = balencefactor(r);
    if(bal>1 && val<r->left->data){
        return rightrotate(r);
    }
    if(bal>1 && val>r->left->data){
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }
    if(bal<-1 && val>r->right->data){
        return leftrotate(r);
    }
    if(bal<-1 && val<r->right->data){
        r->right = rightrotate(r->right);
        return leftrotate(r);
    }
    return r;
}
int main(){
    printf("\n\t\tAVL TREE INSERT AND DELETE\nENTER N : ");
    int n;
    scanf("%d",&n);
    struct node * root = NULL;
    for(int i = 0; i<n;i++){
        printf("\nENTER NODE VALUE : ");
        int v;
        scanf("%d",&v);
        root = insertavl(root,v);
    }
    printf("\n");
    preorder(root);
    printf("\nWHAT VALUE TO DELETE?\n");
    int del;
    scanf("%d",&del);
    root = delnode(root,del);
    printf("\n");
    preorder(root);
    return 0;
}
