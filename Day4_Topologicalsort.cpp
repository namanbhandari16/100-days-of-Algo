//without kahn's algorithm DFS based
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     int V;
     list<int> *adj;
     Graph(int V);
     void topologicalSort();
     void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
     void addEdge(int u,int v);
};
void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}
Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[V];
}

void Graph::topologicalSortUtil(int v,bool visited[],stack<int>&Stack){
    visited[v] = true;
    list<int>::iterator it;
    for(it = adj[v].begin();it!=adj[v].end();++it){
        if(!visited[*it])
          topologicalSortUtil(*it,visited,Stack);
    }
    //push vertex to the stack
    Stack.push(v);
}

void Graph::topologicalSort(){
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    stack<int>Stack;
    for(int i=0;i<V;i++)
      topologicalSortUtil(i,visited,Stack);
    while (!Stack.empty())
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
    
}

int main(){
    Graph myGraph(6); 
    myGraph.addEdge(5, 2); 
    myGraph.addEdge(5, 0); 
    myGraph.addEdge(4, 0);
    myGraph.addEdge(4, 1); 
    myGraph.addEdge(2, 3); 
    myGraph.addEdge(3, 1); 
    myGraph.topologicalSort();
    return 0;
}
