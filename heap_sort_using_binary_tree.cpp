#include <iostream>
#include <queue> 

int n;
int a[100];

using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;
};

struct node * newnode(int v){
    struct node * nn = (struct node *)malloc(sizeof(struct node));
    nn->data = v;
    nn->left = nn->right = NULL;
    return nn;
}

struct node * inserttree(struct node * r, int i){
    if(i<n){
        struct node * temp = newnode(a[i]);
        r = temp;
        r->left = inserttree(r->left,2*i+1);
        r->right = inserttree(r->right,2*i+2);
    }
    return r;
}

void preorder(struct node * r){
    if(r){
        cout<<r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
}

struct node * insertt(struct node * r, int v){
    queue <struct node *> q;
    struct node * temp = r;
    q.push(temp);
    while(((q.front())->left) && ((q.front())->right)){
        struct node * t = q.front();
        q.push(t->left);
        q.push(t->right);
        q.pop();
    }
    struct node * x = q.front();
    if(!x->left){
        x->left = newnode(v);
        return r;
    }
    if(!x->right){
        x->right = newnode(v);
        return r;
    }
	
}

struct node * in(struct node * r, int d){
    if(r){
        if(r->data == d){
            return r;
        }
        in(r->left,d);
        in(r->right,d);
    }
}

struct node * minnode(struct node * r){
    while(r->left){
        r = r->left;
    }
    return r;
}

struct node * arr[1000];

void buildmaxheap(struct node * r){
    if(r->left){
    if(r->data < r->left->data){
        int t = r->data;
        r->data = r->left->data;
        r->left->data = t;
    }}
    if(r->right){
    if(r->data < r->right->data){
        int t = r->data;
        r->data = r->right->data;
        r->right->data = t;
    }}
}

void heapsortt(struct node * r, int nn){
    if(nn == -1){
        return ;
    }
    
    for(int i = (nn)/2 - 1; i >= 0; i--){
        buildmaxheap(arr[i]);
    }
    
    int g = arr[0]->data;
    arr[0]->data = arr[nn]->data;
    arr[nn]->data = g;
    
    cout<<arr[nn]->data<<" ";

    heapsortt(r,nn-1);
    
}

void plo(struct node * r){
    if(r){
        queue <struct node *> q;
        struct node * temp = r;
        q.push(temp);
        while(!q.empty()){
            cout<<q.front()->data<<" ";
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return ;
    }
}

void inorder(struct node * r){
	if(r){
		inorder(r->left);
		cout<<r->data<<" ";
		inorder(r->right);
	}
}
int x=0;
int main()
{
    cout<<"enter n : ";
    cin>>n;
    struct node * root = NULL;
    cout<<"\nenter array elements :\n"; 
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    root = inserttree(root,0);
    preorder(root);
    while(1){
        cout<<"\nchoose any option : 1. insert  2. heapsort 3. preorder 4. exit \n";
        int c;
        cin>>c;
        switch(c){
            case 1 :
                        int f;
                        cout<<"enter element to insert : ";
                        cin>>f;
                        root = insertt(root,f);
                        break;
            case 2 :
			
            		{
                        queue <struct node *> q;
                        struct node * temp = root;
                        q.push(temp);
                        int v = 0;
                        while(!q.empty()){
                            arr[v++] = q.front(); 
                            if(q.front()->left){
                                q.push(q.front()->left);
                            }
                            if(q.front()->right){
                                q.push(q.front()->right);
                            }
                            q.pop();
                        }
			x = v;
                        }

                        heapsortt(root,x-1);
                        //inorder(root);


                        break;
            
            case 3 :     preorder(root);break;
            
            case 4 :     exit(0);break;
            
            default :    cout<<"\nenter correct option\n";
        }
    }
    return 0;
}
