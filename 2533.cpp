#include <iostream>
#include <vector>
#include <string.h>
#define MAX 987654321

using namespace std;

vector<int> dp[2];
vector<vector<int>> G;
bool *visited;

void earlyAdapter(int root) { // 서브 트리의 최소 얼리 어답터 수
    visited[root] = true;
    dp[0][root] = 1;

    for(int next : G[root]) {
        if (visited[next]) continue;
        earlyAdapter(next);
        dp[1][root] += dp[0][next]; 
        dp[0][root] += min(dp[0][next], dp[1][next]);
    }
}

int main() {
    int n; cin >> n;

    visited = new bool[n+1];
    memset(visited, false, n+1);

    dp[0] = vector<int>(n+1, 0);
    dp[1] = vector<int>(n+1, 0);

    G = vector<vector<int>>(n+1);

    for(int i=0;i<n-1;i++) {
        int a, b; 
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    earlyAdapter(1);

    cout << min(dp[1][1], dp[0][1]);
}