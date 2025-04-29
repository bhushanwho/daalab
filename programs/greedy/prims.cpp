#include<bits/stdc++.h> 
using namespace std; 

class edge {
public:
    int src, dst, weight;
    edge() {} 
    edge( int s, int d, int w ) : src(s), dst(d), weight(w) {}
};

struct compare {
    bool operator()(const edge& a, const edge& b) {
        return a.weight > b.weight;
    }
};

void prims(int v, vector<edge> edges) {
    priority_queue<edge, vector<edge>, compare> minHeap;
    unordered_set<int> visited;
    vector<edge> tree;
    visited.insert(1);
    for(const edge& e : edges) {
        if(e.src == 1 || e.dst == 1) {
            if(e.src == 1)
                minHeap.push(e);
            else
                minHeap.push(edge(1, e.src, e.weight));
        }
    }
    while(!minHeap.empty() && tree.size() < v - 1) {
        edge current = minHeap.top();
        minHeap.pop();
        if(visited.find(current.dst) != visited.end())
            continue;
        tree.push_back(current);
        visited.insert(current.dst);
        for(const edge& e : edges) {
            if(e.src == current.dst || e.dst == current.dst) {
                int neighbor = (e.src == current.dst) ? e.dst : e.src;
                if(visited.find(neighbor) == visited.end())
                    minHeap.push(edge(current.dst, neighbor, e.weight));
            }
        }
    }
    for(const edge& e : tree)
        cout << e.src << "-(" << e.weight << ")-" << e.dst << "\n";
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
    prims(v, edges);
    return 0;
    
}
