#include <iostream>
#include <vector>

using namespace std;

vector<int> *G;
int *sub;

void dfs(int cur, int prev) {
    sub[cur]=1;
    for(int next : G[cur]) {
        if (next == prev) continue;
        dfs(next, cur);
        sub[cur] += sub[next];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, R, Q; cin >> N >> R >> Q;

    G = (vector<int>*)calloc(N+1, sizeof(vector<int>));
    sub = (int*)calloc(N+1, sizeof(int));
    // for(int i=1;i<=N;i++) sub[i] = 1;
    for(int i=0;i<N-1;i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(R, -1);
    for(int i=0;i<Q;i++) {
        int input; cin >> input;
        cout << sub[input] << '\n';
    }
}