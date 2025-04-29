#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent,
         unordered_map<int, vector<int>>& adjList,
         unordered_map<int, bool>& visited,
         unordered_map<int, int>& d,
         unordered_map<int, int>& L,
         int& timer,
         set<int>& res) {

    visited[u] = true;
    d[u] = L[u] = timer++;
    int children = 0;

    for (int v : adjList[u]) {
        if (v == parent) continue;
        if (visited[v]) {
            L[u] = min(L[u], d[v]);
        } else {
            dfs(v, u, adjList, visited, d, L, timer, res);
            L[u] = min(L[u], L[v]);
            if (parent != -1 && L[v] >= d[u])
                res.insert(u);
            children++;
        }
    }

    if (parent == -1 && children > 1)
        res.insert(u);
}

set<int> articulationPoints(const vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> adjList;
    for (auto [u, v] : edges) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> d, L;
    set<int> res;
    int timer = 0;

    for (auto& [node, _] : adjList) {
        if (!visited[node]) {
            dfs(node, -1, adjList, visited, d, L, timer, res);
        }
    }

    return res;
}

int main() {

    int e, u, v;
    cin >> e;
    vector<pair<int, int>> edges;
    for (int i = 0; i < e; ++i) {
        cin >> u >> v;
        edges.emplace_back(u, v);
    }

    set<int> res = articulationPoints(edges);
    for (int node : res)
        cout << node << " ";
    cout << '\n';

    return 0;
}
