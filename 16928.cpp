#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int linked[101]={};
    bool visited[101] = {};
    for(int i=0;i<n+m;i++) {
        int s, e; cin >> s >> e;
        linked[s] = e;
    }
    queue<pair<int, int>> Q;
    Q.push({1, 0});
    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int i=1; i <= min(100-cur.first, 6); i++) {
            int nextPos = (linked[cur.first+i] == 0)?(cur.first+i):linked[cur.first+i];
            if (visited[nextPos]) continue;
            visited[nextPos] = true;
            Q.push({nextPos, cur.second+1});
            // cout << nextPos << '\n';
            if (nextPos == 100) {
                cout << cur.second+1;
                return 0;
            }
        }
    }
}