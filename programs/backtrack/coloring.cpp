#include<bits/stdc++.h> 
using namespace std; 


void backtrack( int node, unordered_map<int, vector<int>>& adjList, 
                int c, vector<int>& color, vector<vector<int>>& res ) {
    
    for( int& neighbor : adjList[node] ) {
        if( color[neighbor] == color[node] ) { return; }
    }

    for( int& neighbor: adjList[node] ) {
        if( color[neighbor] == -1 )
            for( int i = 0; i < c; i++ ) {
                color[neighbor] = i;
                backtrack( neighbor, adjList, c ,color, res );
                color[neighbor] = -1;
            }
    }

    bool _complete = true;
    for( int i : color ) {
        if( i == -1 ) _complete = false;
    }

    if( _complete ) {
        res.push_back( color );
    }

}

void graphColoring( unordered_map<int, vector<int>>& adjList, 
                    int c, string clrs ) {
    int vertices = adjList.size();
    vector<int> color(vertices, -1);
    vector<vector<int>> res;

    for( int i = 0; i < c; i++ ) {
        color[0] = i;
        backtrack( 0, adjList, c, color, res );
    }

    for( auto&x : res ) {
        for( int& i : x ) {
            cout << clrs[i] << " ";
        }
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

    string clrs;
    cin >> clrs;

    int c = clrs.size();

    graphColoring( adjList, c, clrs );
    
    return 0; 
} 
