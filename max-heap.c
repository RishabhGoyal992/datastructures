#include<stdio.h>
#include<stdlib.h>

int a[1000];
int n;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int val){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->left = nn->right = NULL;
    return nn;
}

struct node * inserttree(struct node * r, int i){
    if(i<n){
        struct node * temp = newnode(a[i]);
        r = temp;
        r->left = inserttree(r->left,2*i+1);
        r->right = inserttree(r->right,2*i+2);
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

void heapify(struct node * r){
    if(r && r->left && r->right){
        int x = r->data;
        int y = r->left->data;
        int z = r->right->data;
        
        if(x<y){
            int temp = r->data;
            r->data = r->left->data;
            r->left->data = temp;
        }
        if(x<z){
            int temp = r->data;
            r->data = r->right->data;
            r->right->data = temp;
        }
        
        heapify(r->left);
        heapify(r->right);
    }
}

int main(){
    struct node * root = NULL ;
    printf("enter the number of elements : ");
    scanf("%d",&n);
    
    printf("\nenter the elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    root = inserttree(root,0);
    
    preorder(root);
    
    heapify(root);
    
    printf("\n");
    
    preorder(root);
    
    return 0;
}
