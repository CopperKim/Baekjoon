#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int n, m; 
pair<int, int> map[1001][1001];
bool visited[1001][1001];

bool in(vector<int> G, int data) {
    for(int a : G) {
        if (a == data) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string S; cin >> S;
        for(int j=0;j<m;j++) {
            if (S[j] == '0') map[i][j].first = 0;
            if (S[j] == '1') {
                map[i][j].first = -1;
                visited[i][j] = true;
            }
        }
    }

    int group = 1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (visited[i][j] || map[i][j].first != 0) continue;
            int idx=0;
            vector<pair<int, int>> V;
            V.push_back({i, j});
            visited[i][j] = true;

            while(idx < V.size()) {
                int r = V[idx].first, c = V[idx].second;
                idx++;
                if (r-1>=0 && !visited[r-1][c] && map[r-1][c].first == 0) {
                    V.push_back({r-1, c});
                    visited[r-1][c] = true;
                }
                if (r+1 < n && !visited[r+1][c] && map[r+1][c].first == 0) {
                    V.push_back({r+1, c});
                    visited[r+1][c] = true;
                }
                if (c-1 >= 0 && !visited[r][c-1] && map[r][c-1].first == 0) {
                    V.push_back({r, c-1});
                    visited[r][c-1] = true;
                }
                if (c+1 < m && !visited[r][c+1] && map[r][c+1].first == 0) {
                    V.push_back({r, c+1});
                    visited[r][c+1] = true;
                }
            }

            for(pair<int, int> pii : V) {
                // cout << pii.first << ' ' << pii.second << '\n';
                map[pii.first][pii.second] = {V.size(), group};
            }
            group ++;
            // cout << i << ", " << j << " end\n";
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << map[i][j].first << ' ';
    //     }
    //     cout << '\n';
    // }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << map[i][j].second << ' ';
    //     }
    //     cout << '\n';
    // }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (map[i][j].first != -1) {
                cout << 0;
            }
            else  {
                int res=1;
                vector<int> G;
                if (i-1 >= 0 && map[i-1][j].first != -1 && !in(G, map[i-1][j].second)) {
                    res += map[i-1][j].first;
                    G.push_back(map[i-1][j].second);
                }
                if (i+1 < n && map[i+1][j].first != -1 && !in(G, map[i+1][j].second)) {
                    res += map[i+1][j].first;
                    G.push_back(map[i+1][j].second);
                }
                if (j-1 >= 0 && map[i][j-1].first != -1 && !in(G, map[i][j-1].second)) {
                    res += map[i][j-1].first;
                    G.push_back(map[i][j-1].second);
                }
                if (j+1 < m && map[i][j+1].first != -1 && !in(G, map[i][j+1].second)) {
                    res += map[i][j+1].first;
                    G.push_back(map[i][j+1].second);
                }
                cout << (res%10);
            }
        }
        cout << '\n';
    }
}