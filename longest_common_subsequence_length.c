#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
void lcs(char a[],char b[],int len1,int len2){
    int lcs[len1+1][len2+1];
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            lcs[i][j]=0;
        }
    }
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0){
                lcs[i][j]=0;
            }
            if(i>0 && j>0 && a[i-1]!=b[j-1]){
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
            if(i>0 && j>0 && a[i-1]==b[j-1]){
                lcs[i][j]=1+lcs[i-1][j-1];
            }
        }
    }
    printf("\nlcs is : %d \n",lcs[len1][len2]);
}
int main(){
    printf("\nenter first string : ");
    char a[1000];
    scanf("%s",&a);
    printf("\nenter second string : ");
    char b[1000];
    scanf("%s",&b);
    lcs(a,b,strlen(a),strlen(b));
    return 0;
}
