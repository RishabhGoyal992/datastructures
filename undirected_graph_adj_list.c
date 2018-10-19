#include<stdio.h>
#include<stdlib.h>

struct adjnode {
    int value;
    struct abjnode * next ;
};

struct adjlist {
    struct adjnode * head ;
};

struct graph {
    int v;
    struct adjlist * array ;
};

struct adjnode * newnode(int val){
    struct adjnode * nn = (struct adjnode *)malloc(sizeof(struct adjnode));
    nn->value = val;
    nn->next = NULL;
    return nn;
}

struct graph * creategraph(int vertices){
    struct graph * g = (struct graph *)malloc(sizeof(struct graph)) ;
    g->v = vertices ;
    g->array = (struct adjlist *)malloc(vertices *sizeof(struct adjlist));
    for(int i=0;i<vertices;++i){
        g->array[i].head=NULL;
    }
    return g;
}

struct graph * addedges(struct graph * g , int src , int des){
    struct adjnode * newn = newnode(des);
    newn->next = g->array[src].head ;
    g->array[src].head = newn;
    
    struct adjnode * newnn = newnode(src);
    newnn->next = g->array[des].head;
    g->array[des].head = newnn;
} 

void printgraph(struct graph * g){
    
    for(int i=0;i<g->v;++i){
        struct adjnode * x = g->array[i].head;
        printf("%d vertex ",i);
        while(x){
            printf("-> %d ",x->value);
            x=x->next;
        }
        printf("\n");
    }
}

int main(){
    printf("enter v :");
    int v;
    scanf("%d",&v);
    struct graph * g = creategraph(v);
    
    printf("\nenter e :");
    int e;
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("\nenter src :");
        int s ;
        scanf("%d",&s);
        printf("\nenter des :");
        int d;
        scanf("%d",&d);
        addedges(g,s,d);
    }
    printf("\n");
    printgraph(g);
    return 0;
}
