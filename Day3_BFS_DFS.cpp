//thanks gfg.
#include<bits/stdc++.h>
using namespace std;

class Graph{
   public:
     int V; //number of vertex
     list<int> *adj;//adjacency lists
     Graph(int v); 
     void addEdge(int u, int v);
     void bfs(int s);// s is source
     void dfs();
     void dfsUtil(int v,bool visited[]);
};


void Graph::dfsUtil(int v,bool visited[]){
     visited[v] = true;
     cout<<v<<"  ";
     list<int>::iterator it;
     for(auto it = adj[v].begin();it!=adj[v].end();++it){
        if(!visited[*it])
           dfsUtil(*it,visited);
     }
}  

void Graph::dfs(){
  bool * visited = new bool[V];
  //make all unvisited 
  for(int i=0;i<V;i++)visited[i] = false;
  
  for(int i=0;i<V;i++){
     if(!visited[i])
        dfsUtil(i,visited);
  }
}


Graph::Graph(int V){
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
  adj[u].push_back(v);
}

void Graph::bfs(int s){
  bool *visited = new bool[V];
  for(int i=0;i<V;i++)visited[i] = false;
  list<int> queue;
  visited[s] = true;
  queue.push_back(s);
  //to get all the adjacent vertices of a vertex
  list<int>::iterator it;
  while(!queue.empty()){
    //dequeue and print it
    s = queue.front(); 
    cout<<s<<" ";
    queue.pop_front();
    for(it = adj[s].begin();it!=adj[s].end();++it){
       if(!visited[*it]){
          visited[*it] = true;
          queue.push_back(*it);
       }
    }
  }
}

int main(){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    cout<<"followin is bfs traversal\n"; 
    g.bfs(2);
    cout<<"\n";
    cout<<"folowing is dfs traversal\n";
    g.dfs();
  return 0;
    
}
// 4
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 3
// -1
