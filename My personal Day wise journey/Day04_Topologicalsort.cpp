//without kahn's algorithm DFS based
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
     int V;
     list<int> *adj;
     Graph(int V);
     void topologicalSort();
    void topologicalSortKahn();
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
//with kahn's algo
void Graph::topologicalSortKahn(){
   //vector to store indegrees 
   vector<int> inDegree(V,0);
   for(int u=0;u>V;u++){
       list<int>::iterator it;
       for(it = adj[u].begin();it!=adj[u].end();++it){
           inDegree[*it]++;
       }
   }
   //queue to store vertices with indegreee 0
   queue<int> Q;
   for(int i=0;i<V;i++){
       if(inDegree[i]==0){
           Q.push(i);
       }
   }
   int count=0;
   vector<int>TopOrder;
   while(!Q.empty()){
       int front = Q.front();
       Q.pop();
       TopOrder.push_back(front);
       // decrease its neighbour's indegree by one 
       //because we have completed that task 
       list<int>::iterator it;
       for(it = adj[front].begin();it!=adj[front].end();++it){
           if(--inDegree[*it] == 0){
               Q.push(*it);
           }
       }
       count++;
   }
   if(count!=V){
       cout<<"Cycle detected"<<endl;
       return;
   }
   for(auto i : TopOrder){
       cout<<i<<" ";
   }
   cout<<endl;
    
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
