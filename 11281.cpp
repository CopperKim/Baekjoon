#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 
#include <string>

using namespace std;

typedef vector<vector<int>> Graph; 

void dfs_forward(int start, Graph &G, vector<bool> &visited, vector<int> &popOrder) {
    if (visited[start]) return; 
    visited[start] = true; 
    for(int next : G[start]) { 
        dfs_forward(next, G, visited, popOrder); 
    }
    popOrder.push_back(start); 
}

void dfs_reverse(int start, Graph &G, vector<bool> &visited, vector<int> &buffer) {
    if (visited[start]) return; 
    buffer.push_back(start); 
    visited[start] = true; 
    for(int next : G[start]) { 
        dfs_reverse(next, G, visited, buffer); 
    }
}

int X(int x, int &V) {
    if (x > 0) return x; 
    return -x+V; 
}
int notX(int x, int &V) {
    if (x > 0) return x+V; 
    return -x; 
}

void SCC() {
    int V, E; cin >> V >> E;
    
    Graph G(2*V+1), G_r(2*V+1); 

    for(int i=0;i<E;i++) {
        int a, b; cin >> a >> b; 
        G[notX(a, V)].push_back(X(b, V)); 
        G[notX(b, V)].push_back(X(a, V)); 
        G_r[X(a, V)].push_back(notX(b, V));
        G_r[X(b, V)].push_back(notX(a, V)); 
    }

    vector<int> popOrder; 
    vector<bool> visited(2*V+1, false), visited_r(2*V+1, false); 
    vector<vector<int>> buffers; 

    for(int i=1;i<=2*V;i++) dfs_forward(i, G, visited, popOrder); 

    for(int i=2*V-1;i>=0;i--) {
        if (!visited_r[popOrder[i]]) {
            buffers.push_back({}); 
            dfs_reverse(popOrder[i], G_r, visited_r, buffers.back()); 
        }
    }

    vector<int> res(2*V+1, -1); 
    for(int i=0;i<buffers.size();i++) {
        for(auto iter : buffers[i]) {
            res[iter] = i; 
        }
    }


    // for(int i=1;i<=2*V;i++) cout << res[i] << ' ';  
    // cout << '\n'; 

    for(int i=1;i<=V;i++) {
        if (res[i] == res[i+V]) {
            cout << 0; 
            return; 
        }
    }

    cout << "1\n";
    for(int i=1;i<=V;i++) cout << ((res[i] > res[i+V]) ? 1 : 0) << ' '; 
}

int main() {
    SCC(); 
}