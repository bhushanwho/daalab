#include<bits/stdc++.h> 
using namespace std; 

struct edge {
    int u, v, w;
    edge( int _u, int _v, int _w ) : u(_u), v(_v), w(_w) {}
};

int bellmanFord( vector<edge>& edgeList, int vertices, int src, int dst ) {

    int n = edgeList.size();
    bool change = false;
    vector<int> d(vertices+1, 1e9);
    d[src] = 0;

    for( int i = 0; i < n-1; i++ ) {
        change = false;
        for( edge& e : edgeList ) {
            int u = e.u, v = e.v, w = e.w;
            if( d[u] + w < d[v] ) {
                d[v] = d[u] + w;
                change = true;
            } 
        }

        for( int j = 1; j <= vertices; j++ ) {
            cout << d[j] << " ";
        }
        cout << '\n';
        if( !change ) { break; }
    }

    return d[dst];

}

int main() { 

    int vertices, n;
    cin >> vertices >> n;
    vector<edge> edgeList;

    for( int i = 0; i < n; i++ ) {

        int u, v, w;
        cin >> u >> v >> w;
        edgeList.emplace_back(u, v, w);

    }

    bellmanFord( edgeList, vertices, 1, vertices );

    return 0; 
} 
