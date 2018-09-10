/*
Read n words and find the number of unique vowels in each of them:
a. Hashing by Chaining
b. Double Hashing
c. Direct Address Table
d. Linear Probing
e. Quadratic Probing
Input: (n, n-words)
2 
abcdefgdshfkdhfh 
dhfhjhdkfhkdjf
Output:
a e 
none

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
  char str[20];  
};
int vowel[5]={0,0,0,0,0}; 
int main() {
	
	printf("\nenter number of strings :");
	int n;
	scanf("%d",&n);
	
	struct node * a[n];
	for(int i=0;i<n;i++){
	    a[i]=NULL;
	}
	
	for(int i=0;i<n;i++){
	    struct node * s=(struct node *)malloc(sizeof(struct node));
	    printf("\nenter the string :");
	    scanf("%s",(s->str));
	    a[i]=s;
	}
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<strlen(a[i]->str);j++){
	        if(a[i]->str[j]=='a'){
	            vowel[0]=1;
	        }
	        if(a[i]->str[j]=='e'){
	            vowel[1]=1;
	        }
	        if(a[i]->str[j]=='i'){
	            vowel[2]=1;
	        }
	        if(a[i]->str[j]=='o'){
	            vowel[3]=1;
	        }
	        if(a[i]->str[j]=='u'){
	            vowel[4]=1;
	        }
	    }
	    
	    //print vowel
	    //set vowel to 0 
	    printf("\n");
	    
	        if(vowel[0]==1){
	            printf(" a");
	        }if(vowel[1]==1){
	            printf(" e");
	        }if(vowel[2]==1){
	            printf(" i");
	        }if(vowel[3]==1){
	            printf(" o");
	        }if(vowel[4]==1){
	            printf(" u");
	        }
	    
	    int k=0;
	    for(int i=0 ;i<5;i++){
	        if(vowel[i]==1){
	            k=1;
	        }
	    }
	    if(k==0){
	        printf(" none");
	    }
	    
	    for(int i=0;i<5;i++){
	        vowel[i]=0;
	    }
	}
	
	return 0;
}

