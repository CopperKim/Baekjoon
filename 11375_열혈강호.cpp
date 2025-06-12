// https://www.acmicpc.net/problem/11375

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, m; 
int ret=0;
vector<int> tasks[1003];
bool visited[1001];
int work[1001];

bool dfs(int from) {
    visited[from] = true;
    for(int i=0;i<tasks[from].size();i++) {
        int to = tasks[from][i];
        if (work[to] == 0 || !visited[work[to]] && dfs(work[to])) {
            work[to] = from;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    // scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) {
        int t; cin >> t;
        for(int j=0;j<t;j++) {
            int c; 
            // scanf("%d", &c);
            cin >> c; 
            tasks[i].push_back(c);
        }
    }

    for(int i=1;i<=n;i++) {
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ret++;
    }

    cout << ret;
}