//priority queue implementation using decreased priority and arranging the inserted nodes by themselves

#include<iostream>
using namespace std;
struct node {
  int data;
  int priority;
};

struct node queue[1000];
int front=-1;
int rear=-1;
int p=1;

void pqinsert(){
    if(rear==999){cout<<"overflow";return;}
    if((front==-1)&&(rear==-1)){
        rear=0;int d;int p;
        cout<<"\nenter data :";
        cin>>d;
        cout<<"\nenter priority:";
        cin>>p;
        queue[rear].data=d;
        queue[rear].priority=p;
    }else {
        cout<<"\nenter data:";
        int d;
        cin>>d;
        cout<<"\nenter priority:";
        int p;
        cin>>p;
        ++rear;
        {//inserting at correct position
        int i;
        for( i=0;(queue[i].priority)>=p;++i){
            //moving in the array
            }
            int j;
            //point reached
            for( j=rear+1;j>i;--j){
                //shifting of elements
                
                (queue[j].data)=(queue[j-1].data);
                (queue[j].priority)=(queue[j-1].priority);
                }
                //putting value at its place
                (queue[j].data)=d;
                (queue[j].priority)=p;
                
            return;
            }
        
    }
}
void pqmaxdelete(){
    if((front==-1)&&(rear==-1)){
        cout<<"\ninitially empty";
        return;
        }
    if((front==-1)&&(rear==0)){
        cout<<"\nhighest priority initial single item deleted";
        front=0;
        }else{
            if(front==rear-1){
                cout<<"\nqueue is empty";
                ++front;
                return;
                }
            if(front==rear){
		cout<<"\nempty priority queue";
		return;
		}
            front=front+1;
            cout<<"\nhighest priority item deleted";
            }
    
}
void empty(){
    if(front==rear){
        cout<<"\npriority queue is empty !";
        return;
        }
if((front==-1)&&(rear==-1)){cout<<"priority queue is empty !";return;}

if(front==rear){
cout<<"\npriority queue is empty !";return;}

        cout<<"\npriority queue is not empty !";
}

void display(){cout<<endl;
    for(int k=front+1;k<=rear;k++){
        cout<<"data:"<<queue[k].data<<"priority:"<<queue[k].priority<<"   ";
        }cout<<endl;
    }
int main()
{
    while(p){
    cout<<"\nwhat operation would you like to perform\n1.insert according to priority\n2.delete from beginning\n3.if queue is empty?\n4.exit program\n5.display contents of pqueue with priority";
    int choice;
    cin>>choice;
    switch(choice){
        case 1:pqinsert();break;
        case 2:pqmaxdelete();break;
        case 3:empty();break;
        case 4:cout<<"\nprogram exiting..... program exited\n";p=0;break;
        case 5:display();break;
        default:cout<<"\nenter correct value\n";
    }
    
    }

    return 0;
}

