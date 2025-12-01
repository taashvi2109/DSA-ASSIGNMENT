#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";
    for (int nb : adj[node]) {
        if (!vis[nb]) dfs(nb, adj, vis);
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    vector<int> vis(n, 0);
    dfs(start, adj, vis);
}
