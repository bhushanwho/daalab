#include<bits/stdc++.h> 
using namespace std; 
 
struct edge {
    int u, v, w;
    edge( int _u, int _v, int _w ) : u(_u), v(_v), w(_w) {}
};

void printTable( vector<vector<int>>& A, int v ) {
    for( int i = 0; i < v; i++ ) {
        for( int j = 0; j < v; j++ ) {
            if( A[i][j] >= 1e9 ) { cout << "INF\t"; }
            else cout << A[i][j] << '\t';
        }
        cout << '\n';
    }
    cout << "\n\n";
}

void floydWarshall( vector<edge>& edgeList, int v ) {

    vector<vector<int>> A( v, vector<int>(v, 1e9) );
    for( edge& e : edgeList ) {
        int u = e.u, v = e.v, w = e.w;
        A[u-1][v-1] = w;
    }

    for( int i = 0; i < v; i++ ) { A[i][i] = 0; }

    printTable( A, v );

    for( int k = 0; k < v; k++ ) {

        for( int i = 0; i < v; i++ ) {
            for( int j = 0; j < v; j++ ) {
                A[i][j] = min( A[i][j], A[i][k]+A[k][j] );
            }
        }

        printTable( A, v );
    }

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

    floydWarshall( edgeList, vertices );
 
    return 0; 
} 
