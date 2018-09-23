/*
diameter of a binary tree is the number of nodes on the longest path (that may or may not pass through root)
*/

#include<stdio.h>
#include<stdlib.h>
int n;int a[1000];
struct node {
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
struct node * inserttree(struct node * r,int i){
    if(i<n){
        struct node * temp = newnode(a[i]);
        r = temp; 
        r->left = inserttree(r->left,2*i+1);
        r->right = inserttree(r->right,2*i+2);
    }
    return r;
}
int max(int a,int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}
int height(struct node * p ){
    if(p==NULL){
        return 0;
    }else{
        return (max(height(p->left),height(p->right))+1);    
    }
}
int caldiameter(struct node * r){
   if(r==NULL){
       return 0;
   }
    int lheight = height(r->left);
    int rheight = height(r->right);
    
    int ld=caldiameter(r->left);
    int rd=caldiameter(r->right);
    
    return max(lheight+rheight+1,max(ld,rd));
   
}
int main(){
    printf("\nCALCULATING THE DIAMETER OF BINARY TREE\nenter the size of tree : ");
    scanf("%d",&n);
    printf("\nenter the values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root = inserttree(root,0);
    int x = caldiameter(root);
    printf("\ndiameter of the binary tree is : %d \n",x);
    return 0;
}
