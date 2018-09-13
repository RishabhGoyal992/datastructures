#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
char c[50];    
};

int main()
{
    printf("\n\n\t\tchecking unique strings in hash table\n\n");
    
    printf("\n\tenter the size of hash table :");
    int n;
    scanf("%d",&n);
    
    struct node * a[n];
    
    for(int i=0;i<n;i++){
        a[i]=NULL;
    }
    
    for(int i=0;i<n;i++){
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        printf("\n\tenter the string : ");
        scanf("%s",&(newnode->c));
        a[i]=newnode;
    }
    
    printf("\n");
    
    for(int i=0;i<n;i++){
        printf("\na[%d] = %s",i,(a[i]->c));
    }
    
    printf("\n");
    int count =0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if((a[i]!=NULL)&&(a[j]!=NULL))
                        
                        
                     if(strcmp((a[i]->c),(a[j]->c))==0){
                                                a[j]=NULL;
                                                }
                                }
                        }

    
    for(int i=0;i<n;i++){
	if(a[i]!=NULL){
			count = count + 1 ;
		}
	}
    printf("\n\tunique strings are : %d\n\n",(count));
    
    return 0;
}

