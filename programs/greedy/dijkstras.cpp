#include <iostream>
#include <vector>

using namespace std;

int shortestPath( vector<vector<pair<int, int>>> adjList, int src, int dest ) {

        int vertices = adjList.size();

        vector<int> d(vertices, 1e9);
        vector<bool> s(vertices, false);
        int processed = 0;

        d[src] = 0; s[src] = true; processed++;

        for( auto& x : adjList[src] ) {
                d[x.first] = x.second;
        }

        int u, v, cost_uv;

        while( processed <= vertices ) {

                for( int i = 0; i < vertices; i++ ) {
                        if( s[i] == false ) { u = i; break; }
                }
                for( int i = u; i < vertices; i++ ) {
                        if( d[i] < d[u] && s[i] == false ) { u = i; }
                }

                for( auto& x : adjList[u] ) {
                        v = x.first;
                        cost_uv = x.second;

                        if( d[u] + cost_uv < d[v] ) {
                                d[v] = d[u] + cost_uv;
                        }
                }
                s[u] = true; processed++;

        }

        for( int& i : d ) { cout << i << " "; }
        cout << '\n';

        return d[dest];

}