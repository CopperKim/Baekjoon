#include <iostream>
#include <vector>

using namespace std;

int n, m; 
vector<int> *G;
bool visited[1001];

void bfs(int node) {
    for(int a : G[node]) {
        if (!visited[a]) {
            visited[a] = true;
            bfs(a);
        }
    }
}

int main() {
    cin >> n >> m;

    G = (vector<int>*)calloc(n+1, sizeof(vector<int>));

    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int cnt=0;

    for(int i=1;i<=n;i++) {
        if (!visited[i]) {
            cnt++;
            bfs(i);
        }
    }

    cout << cnt;
}