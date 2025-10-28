#include <iostream>
#include <queue>

using namespace std;

int map[1001][1001];

int main() {
    int n, m; cin >> n >> m;
    queue<pair<int, int>> Q;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                Q.push({i, j});
                map[i][j] = 0;
            } if (map[i][j] == 1) {
                map[i][j] = -1;
            }
        }
    }

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();

        if (cur.first-1>=0 && map[cur.first-1][cur.second] == -1) {
            Q.push({cur.first-1, cur.second});
            map[cur.first-1][cur.second] = map[cur.first][cur.second] + 1;
        }
        if (cur.first+1<n && map[cur.first+1][cur.second] == -1) {
            Q.push({cur.first+1, cur.second});
            map[cur.first+1][cur.second] = map[cur.first][cur.second] + 1;
        }
        if (cur.second-1>=0 && map[cur.first][cur.second-1] == -1) {
            Q.push({cur.first, cur.second-1});
            map[cur.first][cur.second-1] = map[cur.first][cur.second] + 1;
        }
        if (cur.second+1<m && map[cur.first][cur.second+1] == -1) {
            Q.push({cur.first, cur.second+1});
            map[cur.first][cur.second+1] = map[cur.first][cur.second] + 1;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}