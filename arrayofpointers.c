/*
 ============================================================================
 Name        : arrayofpointers.c
 Author      : aditya verma
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	printf("enter the rows: ");
	int r;
	scanf("%d",&r);

	printf("\nenter the colomns :");
	int c;
	scanf("%d",&c);
	char *a[c];
	for(int i=0;i<r;i++){
				a[i]=(char *)malloc(c*sizeof(char));
				printf("\nenter the string at %d :",i);
				scanf("%s",a[i]);
	}

	printf("\nentered strings :\n");

	for(int i=0;i<r;i++){
		printf("%s\n",a[i]);
	}


	return 0;
}
