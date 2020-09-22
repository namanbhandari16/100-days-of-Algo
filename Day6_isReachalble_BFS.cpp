//using bfs check is one vertex is reachable to another or not
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     int V;
     list<int> *adj;
     Graph(int V);
     void addEdge(int u,int v);
     bool isReachable(int source,int destination);
};

bool Graph::isReachable(int source,int destination){
      bool * visited = new bool[V];
      for(int i=0;i<V;i++){
          visited[i] = false;
      }
      if(source == destination){
          return true;
      }
      visited[source] = true;
      list<int>Q;
      Q.push_back(source);
      list<int> ::iterator it;
      while(!Q.empty()){
          int first = Q.front();
          Q.pop_front();
          for(it = adj[first].begin(); it!=adj[first].end();++it){
              if(*it == destination){
                  return true;
              }
               if(!visited[*it]){
                  visited[*it] = true;
                  Q.push_back(*it);
              }
          }
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
      Graph g(7); 
    g.addEdge(1, 3); 
    g.addEdge(3, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 5); 
    g.addEdge(5, 4); 
    g.addEdge(2, 1);
    g.addEdge(6, 4); 
    int source , dest;
    cout<<"Please enter source\n";
    cin>>source;
    cout<<"Please enter destination\n";
    cin>>dest;
    if(g.isReachable(source,dest)){
        cout<<"Yes you can go\n";
    }else cout<<"Sorry you cannot go\n";
   
}
