#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;

    int arr[32001];
    for(int i=1;i<=n;i++) arr[i] = i;

    int *inDegree;
    inDegree = (int*)calloc(n+1, sizeof(int));
    vector<int> *G;
    G = (vector<int>*)calloc(n+1, sizeof(vector<int>));

    for(int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        inDegree[b]++;
    }

    priority_queue<int> pq;

    for(int i=1;i<=n;i++) {
        if (inDegree[i] == 0) pq.push(-i);
    }

    for(int i=0;i<n;i++) {
        int cur = -pq.top();
        pq.pop();

        for(int j=0;j<G[cur].size();j++) {
            if (--inDegree[G[cur][j]] == 0) {
                pq.push(-G[cur][j]);
            }
        }

        cout << cur << ' ';
    }

}