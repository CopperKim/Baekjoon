#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int n; cin >> n;
    bool *visited=(bool*)calloc(n+1, sizeof(bool));

    queue<pair<int, int>> Q;
    Q.push({0, n});
    visited[n] = true;

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.second == 1) {
            cout << cur.first;
            return 0; 
        }

        if (cur.second % 3 == 0 && !visited[cur.second/3]) {
            // if (cur.second == 3) {
            //     cout << cur.first+1;
            //     return 0;
            // }
            Q.push({cur.first+1, cur.second/3});
            visited[cur.second/3]=true;
        }
        if (cur.second % 2 == 0 && !visited[cur.second/2]) {
            // if (cur.second == 2) {
            //     cout << cur.first+1;
            //     return 0;
            // }
            Q.push({cur.first+1, cur.second/2});
            visited[cur.second/2]=true;
        }
        if (!visited[cur.second-1]) {
            Q.push({cur.first+1, cur.second-1});
            visited[cur.second-1] = true;
        }
    }
}