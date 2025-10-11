#include <iostream>
#include <vector> 
#include <queue> 
#include <algorithm> 
#include <string>

using namespace std; 

typedef vector<vector<int>> Graph;

void dfs_forward(int &start, Graph &G, vector<bool> &visited, vector<int> &popOrder) {
    if (visited[start]) return; 
    visited[start] = true; 
    for(int next : G[start]) { 
        dfs_forward(next, G, visited, popOrder); 
    }
    popOrder.push_back(start); 
}

void dfs_reverse(int &start, Graph &G, vector<bool> &visited, priority_queue<int> &buffer) {
    if (visited[start]) return; 
    buffer.push(-start); 
    visited[start] = true; 
    for(int next : G[start]) { 
        dfs_reverse(next, G, visited, buffer); 
    }
}

void SCC() {
    int V, E; cin >> V >> E;
    
    Graph G(V+1), G_r(V+1); 

    for(int i=0;i<E;i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); 
        G_r[b].push_back(a); 
    }

    vector<int> popOrder; 
    vector<bool> visited(V+1, false), visited_r(V+1, false);
    int SCC_count = 0; 
    vector<priority_queue<int>> buffers; 

    for(int i=1;i<=V;i++) dfs_forward(i, G, visited, popOrder); 

    for(int i=V-1;i>=0;i--) {
        if (!visited_r[popOrder[i]]) {
            buffers.push_back({}); 
            dfs_reverse(popOrder[i], G_r, visited_r, buffers.back()); 
            SCC_count++; 
        }
    }

    sort(buffers.begin(), buffers.end(), 
        [](const priority_queue<int>& a, const priority_queue<int>& b){
            return -a.top() < -b.top();
        }
    );

    cout << SCC_count << '\n'; 

    for(priority_queue<int> buffer : buffers) {
        while(!buffer.empty()) {
            cout << -buffer.top() << ' ';
            buffer.pop(); 
        }
        cout << "-1\n"; 
    }
}

int main() {
    SCC(); 
}