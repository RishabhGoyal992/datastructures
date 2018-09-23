
#include<stdio.h>
#include<stdlib.h>
int n1,n2;int a1[1000],a2[1000];
struct node {
    int data;
    struct node * left ;
    struct node * right ;
};
struct node * newnode(int d){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = d;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}
struct node * inserttree1(struct node * r , int i){
    if(i<n1){
        struct node * temp = newnode(a1[i]);
        r=temp;
        r->left = inserttree1(r->left,2*i+1);
        r->right = inserttree1(r->right,2*i+2);
    }
    return r;
}
struct node * inserttree2(struct node * r , int i){
    if(i<n2){
        struct node * temp = newnode(a2[i]);
        r=temp;
        r->left = inserttree2(r->left,2*i+1);
        r->right = inserttree2(r->right,2*i+2);
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
int ifidentical(struct node * r1, struct node * r2){
    //when both of them are null
    if((r1==NULL) && (r2==NULL)){
        return 1;
    }
    //when both of them are not null
    if((r1!=NULL) && (r2!=NULL)){
        return((r1->data==r2->data)&&(ifidentical(r1->left,r2->left))&&(ifidentical(r1->right,r2->right)));
    }
    //when either of them is null
    return 0;
}
int main(){
    printf("\n\t\tMAKING TWO BINARY TREES AND CHECKING IF THEY ARE IDENTICAL OR NOT\n");
    printf("\nenter the number of elements in the first tree : ");
    scanf("%d",&n1);
    printf("\nenter the values of first tree : ");
    for(int i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    printf("\nenter the number of  elements of second tree : ");
    scanf("%d",&n2);
    printf("enter the values of second tree : ");
    for(int i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    struct node * root1 = NULL;
    struct node * root2 = NULL;
    root1 = inserttree1(root1,0);
    root2 = inserttree2(root2,0);
    printf("\ninorder of first and second trees are :");
    inorder(root1);
    printf("\n");
    inorder(root2);
    printf("\n");
    if(ifidentical(root1,root2)){
        printf("\nboth trees are identical !");
    }else{
        printf("\nthese are 'not' identical");
    }
    return 0;
}
