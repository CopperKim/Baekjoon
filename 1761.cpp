#include <iostream>
#include <vector> 
#include <math.h>
#include <utility> 

using namespace std;

typedef vector<vector<pair<long long ,long long>>> graph; 
typedef pair<long long, long long> pii;

long long max_depth; 
graph G(40005); // tree graph, (node, cost)
long long depth[40005]; 
pii parent[40005][30]={}; // parent[x][k] : {x 의 2^k 째 조상, x로부터 ~~까지의 cost}     

void DFSparent(long long before, long long root) {
    for(pair<long long, long long> edge : G[root]) {
        if (edge.first == before) continue;
        
        parent[edge.first][0] = {root, edge.second}; 
        for(long long i=1;parent[edge.first][i-1].first != 0;i++) {
            parent[edge.first][i] = {parent[parent[edge.first][i-1].first][i-1].first, \
                                    parent[edge.first][i-1].second + parent[parent[edge.first][i-1].first][i-1].second}; 
        }
        
        depth[edge.first] = depth[root] + 1; 
        max_depth = max(max_depth, depth[edge.first]); 

        DFSparent(root, edge.first); 
    }
}

pair<long long, long long> ascending(long long node, long long height) { // node, cost
    long long cost=0; 
    for(long long i=0;height>0;i++) {
        if (height & 1) {
            cost += parent[node][i].second; 
            node = parent[node][i].first; 
        }
        height = height >> 1; 
    }

    return {node, cost}; 
}

long long minCost(long long a, long long b) {
    if (depth[a] > depth[b]) swap(a, b); //depth a < depth b

    long long cost=0; 

    pair<long long, long long> temp; 
    temp = ascending(b, depth[b]-depth[a]); 
    b = temp.first; 
    cost += temp.second; 

    if (a == b) return cost; 

    for(long long i=max_depth;i>=0;i--) {
        if (parent[a][i].first != 0 && parent[a][i].first != parent[b][i].first) {
            cost += parent[a][i].second + parent[b][i].second; 
            a=parent[a][i].first;
            b=parent[b][i].first;
        }
    }

    cost += parent[a][0].second + parent[b][0].second;
    
    return cost; 
}

int main() {
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    long long N; cin >> N; // number of nodes, cap : 40000
    
    for(long long i=0;i<N-1;i++) {
        long long a, b, c; cin >> a >> b >> c; 
        G[a].push_back({b, c});
        G[b].push_back({a, c}); 
    }

    DFSparent(0, 1); 

    max_depth = (long long)(log2(max_depth)+2); 

    long long M; cin >> M; 

    for(long long i=0;i<M;i++) {
        long long a, b; cin >> a >> b; 
        cout << minCost(a, b) << '\n'; 
    }
}