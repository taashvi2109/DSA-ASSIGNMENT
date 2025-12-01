#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int v, w;
};

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<Node>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> vis(n, 0);
