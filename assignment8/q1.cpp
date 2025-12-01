#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (int nb : adj[x]) {
            if (!vis[nb]) {
                vis[nb] = 1;
                q.push(nb);
            }
        }
    }
}
