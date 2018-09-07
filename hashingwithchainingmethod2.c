#include<stdio.h>
#include<stdlib.h>

int size;

struct node {
int value;
struct node * next;
};

void insertnode(struct node * a[],int val,int index){
    struct node * temp = a[index];
    struct node * newnode=(struct node *)malloc(sizeof(struct node));
    newnode->value=val;
    newnode->next=NULL;
    if(temp==NULL){
        a[index]=newnode;
    }else{
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return;
}
void deletenode(struct node * a[],int ind,int del){
    struct node * temp = a[ind];
    if(temp==NULL){
        printf("\n\ninitially empty hash table");
        return ;
    }struct node * tt = a[ind];
    if((tt->value)==del){
        
        a[ind]=tt->next;
        free(tt);
        return;
    }
    
    while((temp->next->value)!=del){
        temp=temp->next;
    }
    struct node * t =temp->next;
    temp->next=t->next;
    free(t);
    return;
}
void printnode(struct node * a[]){
    for(int i=0;i<size;i++){
        printf("index %d values are :",i);
        struct node * temp = a[i];
        while(temp){
            printf(" %d",temp->value);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    printf("\nHASH TABLE IMPLEMENTATION USING CHAINING\n");
    printf("\nenter the size of the hash table: ");
    
    scanf("%d",&size);
    
    struct node * a[size];
    for(int i=0;i<size;i++){
        a[i]=NULL;
    }
    while(1){
        printf("\nwhat operation would you like to perform ?\n1.insert\n2.delete\n3.print\n4.exit\n");
        int ch;
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nenter the value to insert:");
            int v;
            scanf("%d",&v);
            int i = v%size;
            insertnode(a,v,i);break;
            case 2:
            printf("\nenter the value to delete:");
            int d;
            scanf("%d",&d);
            int indexx=d%size;
            deletenode(a,indexx,d);break;
            case 3:printnode(a);break;
            case 4:exit(0);
            default:printf("\n\twrong input\n");
        }
    }
    return 0;
}
