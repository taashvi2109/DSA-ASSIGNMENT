#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int findp(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return parent[x] = findp(parent[x], parent);
}

void unite(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findp(a, parent);
    b = findp(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);
    for (int i = 0; i < e; i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int total = 0;
    for (auto &ed : edges) {
        if (findp(ed.u, parent) != findp(ed.v, parent)) {
            unite(ed.u, ed.v, parent, rank);
            total += ed.w;
            cout << ed.u << " - " << ed.v << " : " << ed.w << "\n";
        }
    }
    cout << "Total Weight = " << total;
}
