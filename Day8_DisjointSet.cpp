//union find algorithm set-2 gfg 
//by rank and path compression
//this code is just for ref. it has segmentation fault please fix if you can
#include<bits/stdc++.h>
using namespace std;

struct subset{
    int parent;
    int rank;
};

class Graph{
    public:
     int V;
     vector<struct subset >subsets;
     vector<vector<int>> adj;
     Graph(int V);
     void addEdge(int u,int v);
     int find(int i);
     void Union(int i,int j);
     int isCyclic();
};

int Graph::isCyclic(){
   for (int v = 0; v < V; ++v) 
    { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    }
    for(int e = 0;e< adj.size();e++){
         int x = find(adj[e][0]);
         for(auto i: adj[e]){
             int y = find(i);
             if(x==y)
              return 1;
              Union(x,y);
         }
    }
    return 0; 
}

int Graph::find(int i){
   if(subsets[i].parent!=i)
      subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Graph::Union(int x,int y){
    int xroot = find(x);
    int yroot = find(y);
    if(subsets[xroot].rank < subsets[yroot].rank)
       subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot;
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
Graph::Graph(int v){
    this->V = v;
}


int main(){
    Graph g(4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    if(g.isCyclic()) 
     cout<<"Cycle detected\n";
    else cout<<"No cycle\n";

    return 0;
  
}
