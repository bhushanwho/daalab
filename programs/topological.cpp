#include<bits/stdc++.h> 
using namespace std; 
 
vector<int> topologicalSort( unordered_map<int, vector<int>>& adjList ) {

    int n = adjList.size();
    vector<int> indegree(n);
    vector<bool> visited(n);
    vector<int> res(n);

    for( int u = 0; u < n; u++ ) {
        for( int v : adjList[u] ) {
            indegree[v]++;
        }
    }

    for( int i = 0; i < n; i++ ) {
        int node = -1;
        for( int j = 0; j < n; j++ ) {
            if( indegree[j] == 0 && !visited[j]) {
                node = j;
                break;
            }
        }
        if( node == -1 ) { return {}; }
        res[i] = node;
        visited[node] = true;
        for( int v : adjList[node] ) {
            indegree[v]--;
        }
    }

    return res;

}

int main() { 
 
    int edges;
    cin >> edges;
    unordered_map<int, vector<int>> adjList;
    for( int i = 0; i < edges; i++ ) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for( int i : topologicalSort( adjList ) ) {
        cout << i << " ";
    }
    cout << '\n';

    return 0; 
} 
