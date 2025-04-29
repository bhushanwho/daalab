#include<bits/stdc++.h> 
using namespace std; 

class edge {
public:
    int src, dst, weight;
    edge() {} 
    edge( int s, int d, int w ) : src(s), dst(d), weight(w) {}
};

class disjoint_set {
    vector<int> parent;
    vector<int> rank;
public:
    disjoint_set( int n ) {
        parent.resize(n);
        rank.resize(n+1, 0);
        for( int i = 0; i < n ;i++ ) { parent[i] = i; }
    }

    int find(int x) {
        if( parent[x] != x ) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_sets( int x, int y ) {
        int rootx = find(x);
        int rooty = find(y);

        if( rootx != rooty ) {
            if( rank[rootx] > rank[rooty] ) {
                parent[rooty] = rootx;
            }
            else if( rank[rootx] < rank[rooty] ) {
                parent[rootx] = rooty;
            }
            else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

};
    
struct compare {
    bool operator()(const edge& a, const edge& b) {
        return a.weight < b.weight;
    }
};

void kruskals( int v, vector<edge> edges ) {

    vector<edge> tree;
    disjoint_set dsu(v);

    sort( edges.begin(), edges.end(), compare() );

    for( edge e : edges ) {
        if( dsu.find(e.src) != dsu.find(e.dst) ) {
            tree.push_back(e);
            dsu.union_sets(e.src, e.dst);
        }
    }

    for( auto x: tree ) {
        cout << x.src << "-(" << x.weight << ")-" << x.dst << '\n';
    }
}

int main() { 
    int v;
    cin >> v;
    int e;
    cin >> e;
    vector<edge> edges;
    for(int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges.emplace_back(s, d, w);
    }
    kruskals(v, edges);

    
    return 0; 
} 