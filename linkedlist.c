/*
 ============================================================================
 Name        : linkedlist.c
 Author      : aditya verma
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int p=1;
struct node {
	int data;
	struct node * link;
};

void insert(struct node ** h ){
	struct node *newnode=(struct node *)malloc(sizeof(struct node ));
	struct node *t=(*h);
	printf("\nenter the data :");int v;
	scanf("%d",&v);
	newnode->data=v;

	printf("\nenter where you want to perform insertion:\n1.start\n2.end\n3.position\n");
	int c;
	scanf("%d",&c);

	switch(c){

	case 1:

		if((*h)==NULL){
		(*h)=newnode;
		newnode->link=NULL;
	}else{
		newnode->link=(*h);
		(*h)=newnode;
	}


	break;

	case 2:



		while(t->link){
			t=t->link;
		}

		t->link=newnode;
newnode->link=NULL;
		break;


	case 3:

		printf("\nenter the position :");
		int pos;
		scanf("%d",&pos);

		struct node * temp =(*h);


		while(pos!=1){
		temp=temp->link;
		pos--;
		}
		newnode->link=temp->link;
		temp->link=newnode;


		break;

	default:printf("\nwrong value enterred\n");
	}
}

void delete (struct node **h){

printf("\nenter the value that you want to delete : ");
int k;
scanf("%d",&k);

struct node *temp=*h;
struct node *prev;

if(temp->data==k){
	(*h)=temp->link;
	free(temp);
	return;
}

while((temp->data)!=k){
prev=temp;
	temp=temp->link;
}
if(temp==NULL)return;
prev->link=temp->link;
free(temp);
return;

}


void display(struct node *h){
	struct node * temp=(h);
printf("\n");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->link;
	}
	printf("\n");
}


void reverse(struct node **h){

struct node *prev=NULL;
struct node *cur=(*h);
struct node *next =NULL;

while(cur){
	next=cur->link;
	cur->link=prev;
	prev=cur;
	cur=next;

}
(*h)=prev;

}

int main() {
	struct node * head =NULL;
	printf("LINKED LIST \n");
	while(p){

		printf("\nwhat operation would you like to perform ?\n1.insert\n2.delete\n3.display\n4.reverse\n5.exit\n");
		int c;
		scanf("%d",&c);

		switch(c){
		case 1:insert(&head);break;
		case 2:delete(&head);break;
		case 3:display(head);break;
		case 4:reverse(&head);break;
		case 5:printf("\nprogram exiting .... program exited !\n");p=0;break;
		default:printf("\nwrong option enterred!\n");
		}

	}


	return 0;
}
