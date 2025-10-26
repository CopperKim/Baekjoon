#include <iostream>
#include <vector> 
#include <algorithm> 

using namespace std;

int V, E, cnt; 
vector<int> num, parent, low; 
vector<vector<int>> G; 

vector<pair<int, int>> ans; 

void dfs(int x) {
    num[x] = ++cnt; 
    low[x] = num[x]; 
    for(int next : G[x]) {
        if (next == parent[x]) continue; 
        if (!num[next]) {
            parent[next] = x; 
            dfs(next); 
            if (num[x] < low[next]) {
                ans.push_back({min(x, next), max(x, next)}); 
            }
            low[x] = min(low[x], low[next]); 
        }
        else low[x] = min(low[x], num[next]); 
    }
}

int main() {
    cin >> V >> E; 
    G = vector<vector<int>>(V+1); 
    num = vector<int>(V+1, 0); 
    parent = vector<int>(V+1, 0); 
    low = vector<int>(V+1, 0); 
    
    for(int i=0;i<E;i++) {
        int a, b; cin >> a >> b; 
        G[a].push_back(b); 
        G[b].push_back(a); 
    }

    for(int i=1;i<=V;i++) dfs(i); 

    cout << ans.size() << '\n'; 
    sort(ans.begin(), ans.end()); 
    for(auto b : ans) {
        cout << b.first << ' ' << b.second << '\n'; 
    }
}