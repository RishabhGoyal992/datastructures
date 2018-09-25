/*

Read n ints and make a 
binary search tree 
(
BST
)
. Do k search operations to print results as y/n.
Input: (n, x_i, k, y_i)
4
2 1 4 3
3
3 7 1
Output:
y
n
y

*/


#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int val){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct node * inserttree(struct node * r, int val){
    if(!r){
        return newnode(val);
    }
    if(val<=(r->data)){
        r->left = inserttree(r->left,val);
    }else{
        r->right = inserttree(r->right,val);
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

int  searchv(struct node * r, int val){
    if(r){
        if(r->data == val){
            return 1;
        }
        searchv(r->left,val);
        searchv(r->right,val);
    }
}

int n;int a[1000];

int main(){
    printf("\nenter the number of nodes in bst :");
    scanf("%d",&n);
    printf("\nenter the values :");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    struct node * root = NULL;
    root = inserttree(root,a[0]);
    for(int i=1;i<n;i++){
    inserttree(root,a[i]);
    }
    printf("\ninorder is :\n");
    inorder(root);
    printf("\n\n\n");
    while(1){
    printf("\n\nenter the element that you want to search :");
    int v;
    struct node * t = root;
    scanf("%d",&v);
    int y = searchv(t,v);
    printf("\ninorder is :\n");
    inorder(root);
    if(y==1){
        printf("\n\npresent");
    }else{
        printf("\n\nnot present");
    }
    printf("\n\nwould you like to exit?\n1.yes\n2.no\n");
    int g;
    scanf("%d",&g);
    if(g==1){
        return 0;
    }
    
} 
    return 0;
}
