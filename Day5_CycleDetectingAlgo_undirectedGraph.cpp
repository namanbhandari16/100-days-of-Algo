//using dsf aproach learned from gfg
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     int V;
     list<int> *adj;
     Graph(int V);
     void addEdge(int u,int v);
     bool isCyclic();
     bool isCyclicUtil(int v, bool visited[],int parent);
};

bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
   
    visited[v] = true; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    for(int i=0;i<V;i++){
        if(isCyclicUtil(i,visited,-1))
           return true;
    }
    return false;
}


void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[V];
}


int main(){
      Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle\n"; 
    else
        cout << "Graph doesn't contain cycle\n"; 
    return 0; 
}
