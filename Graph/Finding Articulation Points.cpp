#include <bits/stdc++.h>
using namespace std;

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

set<int> artpnt;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                artpnt.insert(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        artpnt.insert(v);
}

void find_cutpoints() {
    timer = 0;
    artpnt.clear();
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

int main()
{
    //Enter the number of nodes in graph :
    cin >> n;

    // create adjacency list for n nodes
    adj = vector<vector<int>>(n);

    //Input the data for 'm' edges in graph
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // u--, v--;
        //Uncomment the above line if input consists of 1 based numbering of nodes

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_cutpoints();

    cout << "The articulation points OR Cut vertices in the graph are : \n";
    for (auto x : artpnt)cout << x << ' ';

    //the set artpnt contains all the articulation poitns in the graph
}
