#include <iostream>
#include <vector>

using namespace std;

void addedge(vector <int> v[],int s,int d){
    v[s].push_back(d);
    v[d].push_back(s);
}

void print(vector <int> v[],int n){
    cout<<"\nADJACENCY LIST FOR GRAPH\n";
    for(int i=0;i<n;i++){
        cout<<i<<"--";
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int v;
    cout <<"enter the number of vertices : "<<"\n";
    cin>>v;
    vector <int> x[v];
    int e;
    cout<<"\n"<<"enter number of edges ";
    cin>>e;
    for(int i=0;i<e;i++){
        cout << "for edge no "<<i+1<<"\n ";
        cout<<"enter src";
        int src;
        cin>>src;
        cout<<"enter des";
        int des;
        cin>>des;
        addedge(x,src,des);
    }
    print(x,v);
    return 0;
}
