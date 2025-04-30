#include<bits/stdc++.h> 
using namespace std; 


void backtrack( int node, int level, 
                int vertices,
                unordered_map<int, vector<int>>& adjList,
                vector<bool>& visited,
                vector<int>& sol,
                vector<vector<int>>& res ) {

    if( level == vertices ) { 
        for( int v : adjList[sol[level-1]] ) {
            if( v == sol[0] ) res.push_back(sol);
        }
    }

    if( node == 0 ) {
        for( int i = 1; i <= vertices; i++ ) {
            visited[i] = true; sol[ level ] = i;
            backtrack( i, level+1, vertices, adjList, visited, sol, res );
            visited[i] = false; sol[ level ] = 0;
        }
    }

    else {

        for( int v : adjList[node] ) {
            if(!visited[v]) { 
                visited[v] = true; sol[ level ] = v;
                backtrack( v, level+1, vertices, adjList, visited, sol, res );
                visited[v] = false; sol[ level ] = 0;
             }
        }

    }


}

void hamiltonianCycles( unordered_map<int, vector<int>>& adjList ) {

    int n = adjList.size();
    vector<bool> visited(n+1);
    visited[0] = true;

    vector<int> sol(n);
    vector<vector<int>> res;

    backtrack(  0, 0, 
                n,
                adjList,
                visited,
                sol,
                res 
            );

    for( vector<int>& v : res ) {
        for( int i : v ) { cout << i << " "; }
        cout << '\n';
    }
    

}
 
int main() { 

    int edges;
    cin >> edges;
    unordered_map<int, vector<int>> adjList;
    for( int i = 0; i < edges; i++ ) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    hamiltonianCycles( adjList );

    return 0; 
} 
