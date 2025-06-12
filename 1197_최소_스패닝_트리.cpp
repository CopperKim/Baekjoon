#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class edge {
public :
    int first, second, cost;
    bool operator<(edge other) {
        return this->cost < other.cost;
    }
};

int n, m; 
int *disjoint;

int find_root(int n) {
    if (disjoint[n] == n) return n;
    else return disjoint[n] = find_root(disjoint[n]);
}

void merge(int x, int y) {
    x=find_root(x);
    y=find_root(y);
    if (x!=y) disjoint[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    disjoint = (int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++) disjoint[i]=i;
    
    vector<edge> edges;
    for(int i=0;i<m;i++) {
        edges.push_back(edge());
        cin >> edges[i].first >> edges[i].second >> edges[i].cost;
    }

    sort(edges.begin(), edges.end());

    int count=0;
    int totalCost = 0;

    for(int i=0;i<m;i++) {
        edge newEdge = edges[i];
        
        if (find_root(newEdge.first) == find_root(newEdge.second)) continue;

        merge(newEdge.first, newEdge.second);

        totalCost += newEdge.cost;
        if (++count == n-1) break;
    }

    cout << totalCost;
}