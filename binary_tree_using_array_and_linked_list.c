/*

binary tree implementation using array and linked list 

*/

#include<stdio.h>
#include<stdlib.h>
int a[1000];int st=0;
int n;int max=0;
struct node {
    int data;
    struct node * left ;
    struct node * right ;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data=d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node * inserttree(struct node * r,int i){
    if(i<n){
        struct node * temp = newnode(a[i]);
        r=temp;
        r->left = inserttree(r->left,2*i+1);
        r->right = inserttree(r->right,2*i+2);
    }
    return r;
}
void inorder(struct node * p){
    if(p){
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
int  calmax(struct node * p){
  if(p){
      if((p->data)>max){
          max=p->data;
      }
      calmax(p->left);
      calmax(p->right);
  }
  return max;
}
int  searchtree(struct node * p,int d){
    if(p!=NULL){
    if((p->data==d)){
        st=1;
    }
    searchtree(p->left,d);
    searchtree(p->right,d);
    }
    return st;
}
int main(){
    printf("\nBINARY TREE IMPLEMENTATION WITH SOME OPERATIONS\n");
    printf("\nenter the size of tree : ");
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nenter the value :");
        scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root=inserttree(root,0);
    printf("\ninorder : ");
    inorder(root);
    printf("\n\n");int m;
    struct node * k = root;
    while(1){
        printf("\nchoose\n1.calculate maximum\n2.exit\n3.search\n");
        int c;
        scanf("%d",&c);
        switch(c){
            case 1:
             m = calmax(k);
            printf("\nmaximum value is : %d\n ",m);
            break;
            case 2:exit (0);
            case 3: printf("\nenter the data to search : \n");
            int d;
            scanf("%d",&d);
            int y=0;
             y = searchtree(k,d);
            if(y==1){
                printf("\nvalue found  ");
                st=0;
            }else{
                printf("\nvalue not found");
                st=0;
            }
            break;
            default:printf("\nchoose corret option\n");
        }
    }
    return 0;
}
