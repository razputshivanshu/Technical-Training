#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int find_routes(const vector<vector<int>>& graph) {
    int min_path = INT_MAX;
    int start = 0;

    vector<int> nodes(graph.size() - 1);
    iota(nodes.begin(), nodes.end(), start + 1);

    do {
        int cost = 0;
        int j = start;
        
        for (int i : nodes) {
            cost += graph[j][i];
            j = i;
        }

        cost += graph[j][start];

        min_path = min(cost, min_path);
    } while (next_permutation(nodes.begin(), nodes.end()));

    return min_path;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << find_routes(graph) << endl;

    return 0;
}
