#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * left;
    struct node * right;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data=d;
    nn->left=nn->right=NULL;
    return nn;
}
struct node * inserttree(struct node * p, int d){
    if(!p){
        return newnode(d);
    }
    if(d<=(p->data)){
        (p->left)=inserttree((p->left),d);
    }else{
        (p->right)=inserttree((p->right),d);
    }
    
    return p;
}
void inorder(struct node * p){
    if(p){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}

void preorder(struct node * p){
    if(p){
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(struct node * p){
    if(p){
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
void searchtree(struct node * p,int d){
    if(!p){
        printf("\nNOT FOUND\n");
        return;
    }
    if(d==(p->data)){
        printf("\nFOUND\n");
        return;
    }
    if(d<=(p->data)){
        searchtree(p->left,d);
    }else{
        searchtree(p->right,d);
    }
    return ;
}
int main(){
    printf("\n\t\t\tBST IMPLEMENTATION\n");
    printf("\tenter the number of elements : ");
    int n;
    scanf("%d",&n);
    int a[n];
    struct node * root =NULL;
    printf("\nenter the elements: \n");
    
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    root=inserttree(root,a[0]);
    for(int i=1;i<n;i++){
         inserttree(root,a[i]);
    }
    
    printf("\nwould you like to search an element?\n1.yes\n2.no\n");
    int i;
    scanf("%d",&i);
    if(i==1){
        struct node * k = root;
        printf("\nenter item to search :");
        int d;
        scanf("%d",&d);
        searchtree(k,d);
    }
    printf("\npreorder of BST : \n");
    preorder(root);
    
    printf("\ninorder of BST : \n");
    inorder(root);
    
    printf("\npostorder of BST : \n");
    postorder(root);
    
    
    return 0;
}
