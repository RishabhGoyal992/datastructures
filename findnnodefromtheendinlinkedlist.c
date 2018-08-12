#include<stdio.h>
#include<stdlib.h>
int p=1;int len=0;
struct node {
int data;
struct node * link;
};

void insert(struct node ** h){
struct node * newnode=(struct node *)malloc(sizeof(struct node));
printf("\nenter node value:");
int a;
scanf("%d",&a);
newnode->data=a;

if((*h)==NULL){
(*h)=newnode;
newnode->link=NULL;
}else{
newnode->link=(*h);
(*h)=newnode;
}
}
void delete(struct node **h){
if((*h)==NULL){
printf("\nempty linked list ");
return;
}
struct node *temp=(*h);

(*h)=(*h)->link;
printf("\ndeleted");
free(temp);
}

void display(struct node *h){
struct node * t=(h);
printf("\n\n");
while(t){
printf("%d ",t->data);
t=t->link;
}
printf("\n\n");
}

int flll(struct node *h){
len=0;
if(h==NULL){return 0;}
struct node *t=(h);
while(t){
len++;
t=t->link;
}
printf("\n%d is the length of the linked list ",len);
return len;
}

void fne(struct node *h){
struct node *temp=(h);
int l=flll(h);
printf("\nenter the node n from the last :");
int n;
scanf("%d",&n);
int k=l-n;
while((k)--){
temp=temp->link;
}
printf("\nvalue at %d is %d",(l-n+1),temp->data);

}


int main(){
struct node * head = NULL;

printf("we are going to find nth node from the last in a linked listin a more efficient way(insertions and deletions are done at the start of the linked list)\n");

while(p){
printf("\nwhat operation would you like to perform ?\n1.insert\n2.delete\n3.display\n4.find length of linked list\n5.find the nth node from the end\n6.exit");
int a;
scanf("%d",&a);
switch(a){
case 1:insert(&head);break;
case 2:delete(&head);break;
case 3:display(head);break;
case 4:flll(head);break;
case 5:fne(head);break;
case 6:printf("\nprogram exiting..... program exited!");p=0;break;

default:printf("\nwrong option chosen");

}

}
return 0;
}


