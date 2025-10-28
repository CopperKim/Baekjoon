#include <iostream>
#include <vector>
#include <queue> 
#include <utility>
#include <tuple> 

using namespace std;

typedef vector<vector<pair<int, int>>> Graph; 

const int MAX = 4000000, MIN = -1; 
int max_depth, LOG=1; 
vector<vector<tuple<int, int, int>>> dp; // dp[x][y] : x로부터 2^y 위 {node, min cost, max cost}
// dp[x][y+1] = {dp[dp[x][y].first][y].first, 
// min(dp[x][y].second, dp[dp[x][y].first][y].second), max(dp[x][y].third, dp[dp[x][y].first][y].third)}

void initialize(int start, int N, Graph &G, vector<int> &depth) {
    queue<int> Q; 
    Q.push(start); 
    depth[start] = 0; 
    vector<int> visited(N+1, false); 
    visited[start] = true;

    while(!Q.empty()) {
        int cur = Q.front(); 
        Q.pop(); 

        for(auto edge : G[cur]) {
            if (visited[edge.first]) continue; 
            visited[edge.first] = true; 
            depth[edge.first] = depth[cur] + 1; 
            dp[edge.first][0] = {cur, edge.second, edge.second}; 
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

tuple<int, int, int> ascending(int &a, int &diff) {
    int maxCost = MIN, minCost = MAX; 
    for(int i=0;diff>0;i++) {
        auto [s, d, f] = dp[a][i]; 
        if (diff & 1) {
            a = s;
            minCost = min(minCost, d); 
            maxCost = max(maxCost, f); 
        }
        diff = diff >> 1;
        
    }
    return {a, minCost, maxCost}; 
}

pair<int, int> LCA(int a, int b, Graph &G, vector<int> &depth) {
    if (depth[b] > depth[a]) swap(a, b); 

    int minCost = MAX, maxCost = MIN, diff = depth[a]-depth[b]; 

    if (diff != 0) {
        auto [q, w, e] = ascending(a, diff); 
        minCost = min(minCost, w); 
        maxCost = max(maxCost, e); 
    }

    if (a == b) return {minCost, maxCost}; 
    for(int i=LOG-1;i>=0;i--) {
        auto [s, d, f] = dp[a][i]; 
        auto [g, h, j] = dp[b][i]; 
        if (s != 0 && s != g) {
            a = s;
            b = g;
            minCost = min(minCost, min(d, h)); 
            maxCost = max(maxCost, max(f, j)); 
        }
    }
    auto [pa0, mna0, mxa0] = dp[a][0];
    auto [pb0, mnb0, mxb0] = dp[b][0];
    minCost = min(minCost, min(mna0, mnb0));
    maxCost = max(maxCost, max(mxa0, mxb0));

    return {minCost, maxCost}; 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int N; cin >> N; 
    Graph G(N+1);
    vector<int> depth(N+1);  
    dp = vector<vector<tuple<int, int, int>>>(N+1, vector<tuple<int, int, int>>(20, {0, MAX, MIN})); 
    for(int i=0;i<N-1;i++) {
        int s, e, c; cin >> s >> e >> c; 
        G[s].push_back({e, c}); 
        G[e].push_back({s, c}); 
    } 
    initialize(1, N, G, depth); 

    for(int i=1;i<=N;i++) max_depth = max(max_depth, depth[i]);

    while ((1 << LOG) <= N) LOG++; 

    for(int i=1;i<LOG;i++) {
        for(int j=2;j<=N;j++) {
            auto [a, b, c] = dp[j][i-1]; 
            auto [d, e, f] = dp[a][i-1]; 
            if (a != 0) dp[j][i] = {d, min(b, e), max(c, f)};
        }
    }

    // for(auto vt : dp) {
    //     for(auto t : vt) {
    //         auto [a, b, c] = t; 
    //         cout << '(' << a << ',' << b << ',' << c << "), "; 
    //     }
    //     cout << '\n'; 
    // }

    int K; cin >> K; 
    while(K--) {
        int a, b; cin >> a >> b;
        auto [s, d] = LCA(a, b, G, depth); 
        cout << s << ' ' << d << '\n'; 
    }
}