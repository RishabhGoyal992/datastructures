#include<stdio.h>
#include<stdlib.h>
#define size 5
struct node {
  int value;
  struct node * next;
};
struct node * a[size],*c,*p;

void insert(int i ,int vall){
    struct node * newnode = (struct node * )malloc(sizeof(struct node));
    newnode->value=vall;
    newnode->next = NULL;
    if(a[i]==NULL){
        a[i]=newnode;
    }else{
        struct node * c= a[i];
        while(c->next){
            c=c->next;
        }
        c->next=newnode;
    }
    return;
}

void deletevalue(int i , int v){
    
    //for value not existing in hash table 
    if(a[i]==NULL){
        printf("\ninitailly empty hash table\n");
        return ;
    }
    
    struct node * p = a[i];
    
    while((p->value!=v)&&((p->next)!=NULL)){
        p=p->next;
    }
    if(p->value== v){
        printf("\n\ndeleting the value ..... \n\n");
    }
    if((p->next)==NULL){
        printf("\n\nvalue does not exist in the hash table\n\n ");
        return 0;
    }
    
    
    struct node * ptr= NULL;
    ptr = a[i];
    
    if((a[i]->value)==v){
        a[i]=ptr->next;
       
        return;
    }
    
    while((ptr->next->value)!=v){
        ptr=ptr->next;
    }
    struct node * t = ptr->next;
    ptr->next = t->next;
    free(t);
}

void printhashvalues(){
    printf("\n\n\nHASH TABLE VALUES\n\n\n");
    for(int i=0;i<size;i++){
        printf("for index : %d , values are : ",i);
        struct node * temp = a[i];
        while(temp){
            printf(" %d",temp->value);
            temp=temp->next;
        }
        printf("\n");
    }
    return ;
}
int main(){
    printf("\n\nHASH TABLE IMPLEMENTATION\n\n");
    while(1){
    printf("\n\n\tpress\n1.insert\n2.delete\n3.print\n4.exit\n\n");
    int ch;
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("\nenter the value to insert :");
        int v;
        scanf("%d",&v);
        int index = v % size;
        insert(index,v);
        break;
        case 2:
        printf("\nenter the value to delete :");
        int vv;
        scanf("%d",&vv);
        int ind = vv % size;
        deletevalue(ind,vv);
        break;
        case 3:
        printhashvalues();
        break;
        case 4:exit(0);
        default: printf("\n\twrong input\n");
    }
    }
    return 0;
}
