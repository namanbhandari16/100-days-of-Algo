#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using PII = pair<int, int>;

int prim(int x, const vector<vector<PII> > &graph) {
    // priority queue to maintain edges with respect to weights
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<bool> marked(graph.size(), false);
    int minimum_cost = 0;

    Q.push(make_pair(0, x));
    while (!Q.empty()) {
        // Select the edge with minimum weight
        PII p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if (marked[x] == true) {
            continue;
        }
        minimum_cost += p.first;
        marked[x] = true;
        for (const PII &neighbor : graph[x]) {
            int y = neighbor.second;
            if (marked[y] == false) {
                Q.push(neighbor);
            }
        }
    }
    return minimum_cost;
}

int main() {
    int nodes = 0, edges = 0;
    cin >> nodes >> edges;  // number of nodes & edges in graph
    if (nodes == 0 || edges == 0) {
        return 0;
    }

    vector<vector<PII> > graph(nodes*2);

    // Edges with their nodes & weight
    for (int i = 0; i < edges; ++i) {
        int x = 0, y = 0, weight = 0;
        cin >> x >> y >> weight;
        graph[x].push_back(make_pair(weight, y));
        graph[y].push_back(make_pair(weight, x));
    }

    // Selecting 1 as the starting node
    int minimum_cost = prim(1, graph);
    cout << minimum_cost << endl;
    return 0;
}