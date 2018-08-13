#include<stdio.h>
#include<stdlib.h>
int p=1;
struct node {
int data;
struct node *link;
};

void pop(struct node ** h){
struct node *temp=(*h);
printf("\n\t%d is dequeued ",temp->data);
(*h)=(*h)->link;
free(temp);

}

void reverse(struct node ** h){
struct node * prev,*cur,*next;
prev=NULL;
cur=NULL;

next=(*h);
cur=next;
while(cur){

next=cur->link;
cur->link=prev;
prev=cur;
cur=next;
}
(*h)=prev;
}

void insert(struct node ** h){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
printf("\nenter a value:");
int n;
scanf("%d",&n);
newnode->data=n;
newnode->link=NULL;
if((*h)==NULL){
(*h)=newnode;
}else{
newnode->link=(*h);
(*h)=newnode;
}
}

void delete(struct node **h){
reverse(h);
pop(h);
reverse(h);
}

void display(struct node **h){
reverse(h);
struct node *temp=(*h);
while(temp){
printf("%d ",temp->data);
temp=temp->link;
}
free(temp);
reverse(h);
}

int main(){
struct node * h=NULL;
printf("we are going to implement queue using one stack \n\n");
while(p){
printf("\nwhat operation would you like to perform ?\n1.insert\n2.delete\n3.display\n4.exit\n");
int c;
scanf("%d",&c);

switch(c){
case 1:insert(&h);break;
case 2:delete(&h);break;
case 3:display(&h);break;
case 4:printf("\nprogram exiting.... program exited!");p=0;break;
default:printf("\nwrong option chosen!");
}


}return 0;
}

