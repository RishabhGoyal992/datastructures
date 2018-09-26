#include<stdio.h>
#include<stdlib.h>
struct node{
   int data;
   struct node * left ;
   struct node * right ;
};
struct node * q[1000];int front=0;int rear=0 ;
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node * maketree(struct node * r,int val){
    if(!r){
        return newnode(val);
    }
    if(val <= r->data){
        r->left = maketree(r->left,val);
    }else{
        r->right = maketree(r->right,val);
    }
    return r;
}
void bfs(struct node * r){
    if(r){
    struct node * temp = r;
    while(temp){
        printf("%d ",temp->data);
        if(temp->left){
            q[++rear]=temp->left;
            }
        if(temp->right){
            q[++rear]=temp->right;
        }
        temp=q[++front];
    }
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
    struct node * root = maketree(root,a[0]);
    for(int i=1;i<n;i++){
        maketree(root,a[i]);
    }
    printf("\nbfs or level order traversal of a tree :\n");
    bfs(root);
    
    return 0;
}
