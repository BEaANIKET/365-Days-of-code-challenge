#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
  public:

    map<T,vector<T>>adj;

    void addEdge(T u,int v,bool direction){
        // directions = 0 ->undirected 
        // directions = 1 ->directed 

        // create an edge from u to v 

        adj[u].push_back(v);

        if(direction){
            adj[v].push_back(u);
        }
    }

    void printAdList(){
        for(auto i : adj){
            cout<<i.first << "->";
            for(auto j : i.second){
                cout<<j << ", ";
            }
            cout<<endl;
        }
    }
};

int main(){

    int n ;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int m ;
    cout<<"Enter the number of edges : ";
    cin>>m;

    graph<int> g;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        // creating a undirected graph
        g.addEdge(u,v,0);
    }
    cout<<endl;

    // Pringng A Graph
    g.printAdList();

return 0;
}
