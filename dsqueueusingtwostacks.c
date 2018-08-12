/*
 ============================================================================
 Name        : datastructures.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int p=1;

struct node{
	int data;
	struct node *link;
};
struct queue{
	struct node *stack1;
	struct node *stack2;
};

void push(struct node ** n, int v){
	struct node * newnode =(struct node *)malloc(sizeof(struct node));
	newnode->data=v;
	if((*n)==NULL){
		(*n)=newnode;
		newnode->link=NULL;
	}else{
		newnode->link=(*n);
		(*n)=newnode;

	}

}
int pop(struct node ** n){
	int r;
	if((*n)==NULL){
		printf("\nstack underflow ");
exit(0);
	}else{
		r=(*n)->data;
		struct node * p=(*n);
		(*n)=(*n)->link;

		free(p);
		return r;
	}
}


void enqueue(struct queue *q){
	printf("\nenter the value :");
	int v;
	scanf("%d",&v);
	push(&(q->stack1),v);
	printf("\n value %d entered!",v);
}

void dequeue(struct queue *q){
	int x;
	if(((q->stack1)==NULL)&&((q->stack2)==NULL)){
		printf("\nQ is empty !");

	}else{
		if((q->stack2)==NULL){
			if((q->stack1)!=NULL){
				while((q->stack1)!=NULL){
					 x =pop(&(q->stack1));
					push(&(q->stack2),x);

				}
			}
		}
			x=pop(&(q->stack2));
			printf("\n%d value  poped!",x);

	}
}

int main() {

	struct queue *q =(struct queue*)malloc(sizeof(struct queue));
	q->stack1=NULL;
	q->stack2=NULL;



printf("we are going to implement queue using two stacks \n");
while(p){
printf("\nwhat operation would you like to perform ?\n1.enqueue\n2.dequeue\n3.exit\n");
int c;
scanf("%d",&c);
switch(c){
case 1:enqueue(q);break;
case 2:dequeue(q);break;
case 3:printf("\nprogram exiting ....program exited!\n");p=0;break;
default:printf("\nentered wrong value");
}

}
return 0;
}
