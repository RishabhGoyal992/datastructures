#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int value;
};

int main(){
	printf("\nenter the size : ");
	int n;
	scanf("%d",&n);
	struct node * a[n];
	for(int i=0;i<n;i++){
		a[i]=NULL;
	}
	for(int i=0;i<n;i++){
	printf("\nenter the value : ");
	struct node * x = (struct node * )malloc(sizeof(struct node));
	scanf("%d",&(x->value));
	a[i]=x;
	}

	for(int i=0;i<n;i++){
	printf("||%d|| -->> %d",i,(a[i]->value));
	printf("\n");
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((a[i]!=NULL)&&(a[j]!=NULL)){
				if((a[i]->value)==(a[j]->value)){
					a[j]=NULL;
				}	}
		}
	}

	int count =0;
	
	for(int i=0;i<n;i++){
		if(a[i]!=NULL){
			count = count +1;
		}
	}

	printf("\nnumber of unique values : %d \n",count);
	return 0;
}
