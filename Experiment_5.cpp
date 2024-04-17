#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from, to, weight;

    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            rank[rootV]++;
        }
    }
};

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    int g_edges = g_from.size();

    vector<Edge> edges;
    for (int i = 0; i < g_edges; i++) {
        edges.push_back(Edge(g_from[i], g_to[i], g_weight[i]));
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    DisjointSet ds(g_nodes);

    int totalWeight = 0;

    for (const Edge &edge : edges) {
        int rootFrom = ds.find(edge.from);
        int rootTo = ds.find(edge.to);

        if (rootFrom != rootTo) {
            ds.unionSets(rootFrom, rootTo);
            totalWeight += edge.weight;
        }
    }

    return totalWeight;
}

int main() {
    int g_nodes, g_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> g_nodes >> g_edges;

    vector<int> g_from(g_edges), g_to(g_edges), g_weight(g_edges);

    cout << "Enter the edges (from to weight):" << endl;
    for (int i = 0; i < g_edges; i++) {
        cin >> g_from[i] >> g_to[i] >> g_weight[i];
    }

    int result = kruskals(g_nodes, g_from, g_to, g_weight);

    cout << "Total weight of the minimum spanning tree: " << result << endl;

    return 0;
}