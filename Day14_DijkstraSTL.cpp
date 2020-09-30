//https://stackoverflow.com/questions/56780844/how-to-remove-root-node-from-heap
// https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/
//and
 //https://www.geeksforgeeks.org/implement-min-heap-using-stl/
// most of the credit goes to gfg
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f 
typedef pair<int,int> iip;
class Graph{
    int V;
    list<pair<int,int> > *adj;
   public:
   Graph(int v);
   void addEdge(int u,int v,int w);
   void shortestPath(int s);
};

Graph::Graph(int v){
    this->V = v;
    adj = new list<pair<int,int> >[V];
}
void Graph::addEdge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int src){
    priority_queue<iip,vector<iip>,greater<iip>>pq;
    vector<int>dist(V,INF);
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        list<pair<int,int> >::iterator it;
        for(it = adj[u].begin();it!=adj[u].end();++it){
            int v = it->first;
            int w = it->second;
            //if there is a shorter path b/w u and v
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
 printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]);

}

int main(){
      int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestPath(0); 
    return 0;
}
