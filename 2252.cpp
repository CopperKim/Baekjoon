#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m; 
    cin >> n >> m;
    vector<int> *G = (vector<int>*)calloc(n+1, sizeof(vector<int>));
    int *inDegree = (int*)calloc(n+1, sizeof(int));

    for(int i=0;i<m;i++) {
        int a, b; 
        cin >> a >> b;
        G[a].push_back(b);
        inDegree[b]++;
    }

    queue<int> Q; 
    for(int i=1;i<=n;i++) {
        if (inDegree[i] == 0) {Q.push(i);}
    }

    int *res = (int*)calloc(n, sizeof(int));

    for(int i=0;i<n;i++) {
        int x=Q.front();
        Q.pop();
        res[i] = x;
        for(int y : G[x]) {
            if (--inDegree[y] == 0) {
                Q.push(y);
            }
        }
    }

    for(int i=0;i<n;i++) cout << res[i] << ' ';
}