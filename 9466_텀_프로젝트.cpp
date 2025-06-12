#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, noteam;
int *arr;
bool *visited;
vector<int> cycle;

int dfs(int m) {
    if (visited[m]) {
        auto f = find(cycle.begin(), cycle.end(), m);
        if (f == cycle.end()) return 0;
        noteam -= distance(f, cycle.end());

        return 0;
    }
    visited[m] = true;
    cycle.push_back(m);
    return dfs(arr[m]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    while(T--) {
        cin >> n; noteam = n;
        arr = (int*)calloc(n+1, sizeof(int));
        visited = (bool*)calloc(n+1, sizeof(bool));
        for(int i=1;i<=n;i++) cin >> arr[i];

        for(int i=1;i<=n;i++) {
            dfs(i);
            cycle.clear();
        }

        cout << noteam << '\n';

        free(arr);
        free(visited);
    }
}