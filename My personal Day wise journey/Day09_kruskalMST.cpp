#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
     int weight;
     int src;
     int dest;
};

class subset{
    public:
     int parent;
     int rank;
};

class Graph{
    public:
     int V,E;
     Edge* edges;
};

Graph * createGraph(int V,int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edges = new Edge[E];
    return graph;
};

int wComp(const void*a,const void* b){
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
}

int find(subset subsets[],int i){
    if(subsets[i].parent != i)
      subsets[i].parent = find(subsets,subsets[i].parent);
     return subsets[i].parent ;
}

void Union(subset subsets[],int i,int j){
     //find in whcih subset i and j belongs 
     int iRoot = find(subsets,i);
     int jRoot = find(subsets,j);
    if(subsets[iRoot].rank < subsets[jRoot].rank){
        subsets[iRoot].parent =jRoot;
    }
    else if(subsets[iRoot].rank > subsets[jRoot].rank){
        subsets[jRoot].parent = iRoot;
    }
    else {
        //equal case
        //make any parent doesnot matter
        subsets[iRoot].parent = jRoot;
        subsets[jRoot].rank++;
    }
}

void KruskalMST(Graph * graph){
    int V = graph->V;
    int E = graph->E;
    Edge result[V];
    subset * subsets = new subset[(V*sizeof(subset))];
    //initialize subsets 
    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].rank = -1;
        //initialize ranks by -1
    }
    qsort(graph->edges,graph->E,sizeof(graph->edges[0]),wComp);
     int e =0;
     int i=0;
     while(e < V - 1 && i < graph->E){
        Edge next_edge = graph->edges[i++];
        int x = find(subsets, next_edge.src);
        int y =find(subsets, next_edge.dest);
         if(x!=y){
             // no cycle
             Union(subsets,x,y);
             result[e++] = next_edge;
         }
         //else discard next edge
     }
     cout<<"Following are the edges in the constructed MST\n";  
    for (i = 0; i < e; ++i)  
        cout<<result[i].src<<" -- "<<result[i].dest<<" == "<<result[i].weight<<endl;  
    return;
}

int main(){
    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph* graph = createGraph(V, E);  
  
  
    // add edge 0-1  
    graph->edges[0].src = 0;  
    graph->edges[0].dest = 1;  
    graph->edges[0].weight = 10;  
  
    // add edges 0-2  
    graph->edges[1].src = 0;  
    graph->edges[1].dest = 2;  
    graph->edges[1].weight = 6;  
  
    // add edges 0-3  
    graph->edges[2].src = 0;  
    graph->edges[2].dest = 3;  
    graph->edges[2].weight = 5;  
  
    // add edges 1-3  
    graph->edges[3].src = 1;  
    graph->edges[3].dest = 3;  
    graph->edges[3].weight = 15;  
  
    // add edges 2-3  
    graph->edges[4].src = 2;  
    graph->edges[4].dest = 3;  
    graph->edges[4].weight = 4;  
  
    KruskalMST(graph);  
  
    return 0;  
}
