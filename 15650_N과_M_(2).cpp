#include <iostream>

using namespace std;

int n, m; 
int arr[8];
bool visited[8];

void dfs(int rank, int num) { // end+1 ~ n-m+rank+1 까지 가능
    if (rank == m) {
        for(int i=0;i<m;i++) {
            cout << arr[i] << ' ';
            visited[i] = false;
        }
        cout << '\n';
        return;
    }
    for(int i=num;i<=n;i++) {
        if (visited[i]) continue;
        arr[rank] = i;
        visited[i] = true;
        dfs(rank+1, i+1);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    dfs(0, 1);
}