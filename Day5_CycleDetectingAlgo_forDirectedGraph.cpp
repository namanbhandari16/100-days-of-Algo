//using dsf aproach learned from gfg for directed graph
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     int V;
     list<int> *adj;
     Graph(int V);
     void addEdge(int u,int v);
     bool isCyclic();
     bool isCylclicUtil(int v, bool*visited,bool*recStack);
};

bool Graph::isCylclicUtil(int v, bool*visited,bool*recStack){
    if(!visited[v]){
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator it;
        for(it = adj[v].begin();it!=adj[v].end();++it){
             if(!visited[*it] && isCylclicUtil(*it,visited,recStack))
                return true;
             else if(recStack[*it])
               return true;
        }
    }
    recStack[v] = false;
    return false;

}

bool Graph::isCyclic(){
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i=0;i<V;i++){
        if(isCylclicUtil(i,visited,recStack))
           return true;
    }
    return false;
}


void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
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
