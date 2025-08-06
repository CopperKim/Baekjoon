#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph; 

queue<vector<int>> ans; 

void DFS(int first, vector<int>& SCC, vector<bool>& finished, graph& G) {
    queue<int> Q; Q.push(first);
    SCC[first] = first; 

    while(!Q.empty()) {
        int cur = Q.front(); 

        for(int next : G[cur]) {
            
            if (SCC[next] == next) {
                
                ans.push(vector<int>()); 
                
                while(Q.front() != next) {
                    ans.front().push_back(Q.front()); 
                    Q.pop(); 
                }
                ans.front().push_back(Q.front()); 
                Q.pop(); 

            }

            else 
        }
    }
}

int main() {
    int V, E ; cin >> V >> E; 
    
    graph G; 

    for(int i=0;i<E;i++) {
        int a, b; cin >> a >> b; 
        G[a].push_back(b); 
    }

    vector<int> SCC(V+1);
    vector<bool> finished(V+1); 

    for(int i=1;i<=V;i++) {
        SCC[i] = 0; 
        finished[i] = false; 
    }

    for(int i=1;i<=V;i++) {
        if (!finished[i]) DFS(i, SCC, finished, G); 
    }
}