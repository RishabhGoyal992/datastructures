#include<iostream>
#include<stack>
using namespace std;

struct node {
	char data;
	struct node * left;
	struct node * right;
};

struct node * newnode(char d){
	struct node * nn = (struct node *)malloc(sizeof(struct node));
	nn->data = d;
	nn->left = nn->right = NULL;
	return nn;
}

char exp[100];

void inorder(struct node * r){
	if(r){
		inorder(r->left);
		cout<<r->data<<" ";
		inorder(r->right);
	}
}

void printstack(stack <struct node *> s){
	stack <struct node *> x = s;
	cout<<"\n";
	while(!x.empty()){
		inorder(x.top());
		x.pop();
	}
	cout<<"\n";
}

void evaluate(char exp[], int size){
	stack <struct node *> s;
	for(int i=0;i<size;i++){
		if(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/'){
			struct node * temp1 = newnode(exp[i]);
			struct node * temp2 = s.top();
			s.pop();
			struct node * temp3 = s.top();
			s.pop();

			temp1->left = temp3;
			temp1->right = temp2;

			s.push(temp1);
		}else{
			struct node * t = newnode(exp[i]);
			s.push(t);
		}
	}
	printstack(s);
	return;
}

int main(){
	int n;
	cout<<"enter expression size : ";
	cin>>n;
	
	cout<<"\nenter expression char by char : \n";
	for(int i=0;i<n;i++){
		cin>>exp[i];
	}
	evaluate(exp,n);
	return 0;
}
