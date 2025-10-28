#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

const int MAX_V = 10003; 

vector<int> adj[MAX_V];
int num[MAX_V], low[MAX_V], par[MAX_V], cnt;
vector<int> articulation; 
vector<bool> isArt; // 중복 방지

void dfs(int x) {
    num[x] = low[x] = ++cnt;
    int childCnt = 0;

    for (int nxt : adj[x]) {
        if (nxt == par[x]) continue;

        if (!num[nxt]) {               // tree edge
            par[nxt] = x;
            ++childCnt;
            dfs(nxt);

            // 비-루트 단절점 조건
            if (par[x] != 0 && low[nxt] >= num[x])
                if (!isArt[x]) { isArt[x] = true; articulation.push_back(x); }

            low[x] = min(low[x], low[nxt]);
        } else {                        // back edge (to ancestor)
            low[x] = min(low[x], num[nxt]);
        }
    }

    // 루트 단절점 조건: 자식 2개 이상
    if (par[x] == 0 && childCnt >= 2)
        if (!isArt[x]) { isArt[x] = true; articulation.push_back(x); }
}

int main() {
    int N, E; cin >> N >> E; 

    for(int i = 1;i<=E;i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    fill(num, num+MAX_V, 0);
    fill(low, low+MAX_V, 0);
    fill(par, par+MAX_V, 0);
    cnt = 0;
    isArt.assign(MAX_V, false);

    for (int v = 1; v <= N; ++v)
        if (!num[v]) dfs(v);

    cout << articulation.size() << '\n'; 
    sort(articulation.begin(), articulation.end()); 
    for(int a : articulation) cout << a << ' '; 
}
