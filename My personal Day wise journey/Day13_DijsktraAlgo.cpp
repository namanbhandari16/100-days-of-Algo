//thanks to gfg for cool explanation
#include<bits/stdc++.h>
#define V 9 
using namespace std;

int getMinEdge(int distance[],bool visited[]){
     int minEl=INT_MAX,min_ind=-1;
     for(int i=0;i<V;i++){
         if(!visited[i] && distance[i]< minEl){
             minEl = distance[i];
             min_ind =i;
         }
     }
     return min_ind;
};


void printSolution(int dist[]){
    for(int i=0;i<V;i++){
        cout<<i<<"-"<<dist[i]<<endl;
    }
}


void dijkstra(int graph[V][V],int src){
    bool visited[V];
    int distance[V];
    for(int v=0;v<V;v++){
        visited[v] = false;
        distance[v] = INT_MAX;
    }
    //mark src as visited and distance as 0
    distance[src] =0;
    for(int count=0;count<V-1;count++){
        //explore adj edges of cur node and get minimum edge
        int minU = getMinEdge(distance,visited);
        visited[minU] = true;
        //update adj edge only if it is not visited and there is edge in graph
        for(int i=0;i<V;i++){
            if(!visited[i] && graph[minU][i] && distance[minU]!=INT_MAX
                && distance[minU] + graph[minU][i] < distance[i]
            )distance[i] = distance[minU] + graph[minU][i];
        }
       
    } printSolution(distance);
}

int main(){
//copied from gfg
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    dijkstra(graph, 0); 
    return 0;
}
