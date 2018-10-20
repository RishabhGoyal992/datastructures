#include <stdio.h>
#include <stdlib.h>

int find(int i,int parent[i]){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void unionn(int i,int j,int parent[]){
    int a = find(i,parent);
    int b = find(j,parent);
    parent[a]=b;
}

void krushkalmst(int v,int c[][v]){
    int parent[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    
    int mincost = 0;
    int edgecount = 0;
    while(edgecount<v-1){
        int min = 999;
        int a=-1;int b=-1;
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(find(i,parent)!=find(j,parent) && c[i][j]<min){
                    min = c[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionn(a,b,parent);
        printf("edge %d : (%d,%d) cost : %d \n",edgecount++,a,b,min);
        mincost += min;
    }
    printf("\nmst cost : %d",mincost);
}

int main()
{
    printf("enter v : ");
    int v;
    scanf("%d",&v);
    
    int cost[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cost[i][j]=999;
        }
    }
    
    printf("\nenter number of edges : ");
    int e;
    scanf("%d",&e);
    
    for(int i=0;i<e;i++){
        int value ;
        int index1;int index2;
        printf("\nenter index1 and index2 : ");
        scanf("%d %d",&index1,&index2);
        printf("\nenter cost for (%d,%d) :",index1,index2);
        scanf("%d",&value);
        cost[index1][index2]=value;
        cost[index2][index1]=value;
    }
    
    krushkalmst(v,cost);
    
    return 0;
}
