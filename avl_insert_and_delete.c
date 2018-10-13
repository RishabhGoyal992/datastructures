#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left ; 
    struct node * right ;
    int height;
};
struct node * newnode(int val){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->height = 1;
    nn->left = NULL;
    nn->right = NULL;
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
int balfac(struct node * r){
    if(!r){
        return 0;
    }else{
        return (height(r->left)-height(r->right));
    }
}
struct node * leftrotate(struct node *x){
    struct node * y = x->right;
    struct node * t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return y;
}
struct node * rightrotate(struct node * y){
    struct node * x = y->left ;
    struct node * t2 = x->right ;
    x->right = y;
    y->left = t2;
    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;
    return x;
}
struct node * insertavl(struct node * r , int val){
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
    int bal = balfac(r);
    //four cases
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
void preorder(struct node * r){
    if(r){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}
struct node * minnode(struct node * r){
    while(r->left){
        r= r->left;
    }
    return r;
}
struct node * delnode(struct node * r ,int val){
    if(!r){
        return NULL;
    }
    if(val < r->data){
        r->left = delnode(r->left,val);
    }else if (val > r->data){
        r->right = delnode(r->right,val);
    }else{
        if(r->left == NULL){
            struct node * temp = r->right;
            free(r);
            return temp;
        }
        if(r->right == NULL){
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
    int bal = balfac(r);
    
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
    printf("enter n :");
    int n;
    scanf("%d",&n);
    struct node * root = NULL;
    for(int i=0;i<n;i++){
        printf("\nenter data value : ");
        int v;
        scanf("%d",&v);
        root = insertavl(root,v);
    }
    preorder(root);
    while(1){
        printf("\n\nCHOOSE\n1.insert\n2.delete\n3.print preorder\n4.exit\n\n");
        int c;int x;
        scanf("%d",&c);
        switch(c){
            case 1:
            printf("\nenter node value :\n");
            scanf("%d",&x);
            root = insertavl(root,x);break;
            case 2:
            printf("\nenter the node value to delete : \n");
            int d;
            scanf("%d",&d);
            root = delnode(root,d);
            break;
            case 3:
            preorder(root);
            break;
            case 4:
            exit(0);
            break;
            default:printf("\n\tchoose correct option\n");
            break;
        }
    }
    return 0;
}
