#include<bits/stdc++.h> 
using namespace std; 
 
bool checkDAG( unordered_map<int, vector<int>> adjList ) {

    vector<bool> visited( adjList.size() );
    queue<int> q;
    int u = adjList.begin()->first;

    q.push(u);

    while( !q.empty() ) {
        u = q.front(); q.pop();
        visited[u] = true;

        for( int v : adjList[u] ) {
            if( !visited[v] ) {
                q.push(v);
            }
            else return false;
        }
    } 

    return true;

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

    cout << checkDAG( adjList ) << '\n';

    return 0; 
} 
