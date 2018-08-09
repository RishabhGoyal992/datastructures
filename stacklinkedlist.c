#include <stdio.h>
#include <stdlib.h>
int p=1;
struct node {
	int data;
	struct node *link;

};

void push(struct node **h){
	printf("\nenter the value that you want to enter :");
	int v;
	scanf("%d",&v);
	struct node *newnode =(struct node *)malloc(sizeof(struct node));
	newnode->data=v;

	if((*h)=='\0'){
		printf("\ninitially empty stack!putting in the first value:%d\nvalue is in!\n",v);
		(*h)=newnode;
		newnode->link='\0';
	}else{
		printf("\nentering the value %d in the stack ... value entered!",v);
		newnode->link=(*h);
		(*h)=newnode;
	}
}
void pop(struct node ** h){
	if((*h)=='\0'){
		printf("\nempty stack!\npush some elements\n");
	}else{
		struct node *t=(*h);
		(*h)=(*h)->link;
		printf("\npoped one element\n");
		free(t);
	}

}
void display(struct node *h){
	printf("\n\nstack elements are\n");
	struct node *t=(h);
	while(t!='\0'){
		printf("%d\n",t->data);
		t=t->link;
	}
}

void isempty(struct node *h){
	if(h=='\0'){
		printf("\nstack is empty\n");
	}else{
		printf("\nstack has some elements\n");
	}
}
int main() {


printf("stack implementation using  linked list \n");
struct node * head='\0';

while(p){
printf("\nchoose any option\n1.push\n2.pop\n3.display\n4.isempty?\n5.exit");
int c;
scanf("%d",&c);


switch(c){
case 1:push(&head);break;
case 2:pop(&head);break;
case 3:display(head);break;
case 4:isempty(head);break;
case 5:printf("\nprogram exiting ..... program exited!");p=0;break;
default:printf("\nwrong option");
}


}
	return 0;
}
