#include<stdio.h>
#include<stdlib.h>

int a[1000];
int n;int x, y, z;

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * queue[1000];
int front = 0;
int rear = 0;

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
    if(r && (r->left || r->right)){
         x = r->data;
        if(r->left){
             y = r->left->data;
        }
        if(r->left==NULL){
             y = -1000;
        }
        if(r->right){
             z = r->right->data;
        }
        if(r->right==NULL){
             z = -1000; 
        }
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
    }
}

void save(struct node * r){
    queue[rear++] = r;
    while(r){
        if(r){
            if(r->left){
                queue[rear++]=r->left;
            }
            if(r->right){
                queue[rear++]=r->right;
            }
            r = queue[front++];
        }
    }
    front = 0;
}

int main(){
    struct node * root = NULL ;
    printf("MAX-HEAP\nenter the number of elements : ");
    scanf("%d",&n);
    
    printf("\nenter the elements : \n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
    root = inserttree(root,0);
    
    preorder(root);
    
    save(root);
    
    for(int i = rear-1; i>=0; i--){
        heapify(queue[i]);
    }
    printf("\n");
    
    preorder(root);
    
    return 0;
}
