#include <iostream>
#include <vector>
#include <queue> 
#include <utility>
#include <tuple> 

using namespace std;

typedef vector<vector<pair<int, int>>> Graph; 

const int MAX = 10000001, MIN = -1; 

void calc_depth(int start, int N, Graph &G, vector<int> &depth, vector<int> &parent) {
    queue<int> Q; 
    Q.push(start); 
    depth[start] = 0; 
    vector<int> visited(N+1, false); 
    visited[start] = true;

    while(!Q.empty()) {
        int cur = Q.front(); 
        Q.pop(); 
        visited[cur] = true; 

        for(auto edge : G[cur]) {
            if (visited[edge.first]) continue; 
            depth[edge.first] = depth[cur] + 1; 
            parent[edge.first] = cur; 
            Q.push(edge.first); 
        }
    }

    return; 
}

int cost(int a, int b, Graph &G) { 
    // a to b 간선의 cost 를 반환 
    for(auto p : G[a]) { 
        if (p.first == b) return p.second; 
    }
    return -1; 
}

pair<int, int> SCA(int a, int b, Graph &G, vector<int> &depth, vector<int> &parent) {
    if (depth[b] > depth[a]) swap(a, b); 

    int maxCost = MIN, minCost = MAX; 

    // 

    return {minCost, maxCost}; 
}

int main() {
    int N; cin >> N; 
    Graph G(N+1);
    vector<int> depth(N+1), parent(N+1, 0);  
    for(int i=0;i<N-1;i++) {
        int s, e, c; cin >> s >> e >> c; 
        G[s].push_back({e, c}); 
        G[e].push_back({s, c}); 
    }

    parent[1] = 1; 
    calc_depth(1, N, G, depth, parent); 

    int K; cin >> K; 
    while(K--) {
        int a, b; cin >> a >> b;
        pair<int, int> res = SCA(a, b, G, depth, parent); 
        cout << res.first << ' ' << res.second << '\n'; 
    }
}