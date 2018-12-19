#include <iostream>
#include <vector>
using namespace std;

void addedge(vector <int> v[],int i, int src , int des){
    v[src].push_back(des);
    v[des].push_back(src);
}

void print(vector <int> v[],int ver){
    for(int i=0; i < ver; i++){
        cout << i <<"--";
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] <<" ";
        }
        cout << "\n";
    }
}

int main()
{
    int v;
    cout<<"enter the number of vertices in the graph : "<<"\n";
    cin>>v;
    vector <int> a[v];
    cout<<"enter the number of edges you want to enter : "<<"\n"; 
    int n;
    cin>>n;
    for(int i=0; i < n; i++){
        cout<<"edge no "<<i+1<<" \n";
        cout<<"enter src";
        int src;
        cin>>src;
        cout<<"enter des ";
        int des;
        cin>>des;
        addedge(a,i,src,des);
    }
    cout<<"\n";
    print(a,v);
    return 0;
}
