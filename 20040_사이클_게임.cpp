#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int *disjoint;

int find(int idx) {
    if (idx == disjoint[idx]) return idx;
    return disjoint[idx] = find(disjoint[idx]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    disjoint[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m; cin >> n >> m;
    disjoint = (int*)calloc(n+1, sizeof(int));
    for(int i=1;i<=n;i++) disjoint[i] = i;

    vector<pair<int, int>> V;
    for(int i=1;i<=m;i++) {
        int a, b; cin >> a >> b;
        V.push_back({a, b});
    }

    for(int i=1;i<=m;i++) {
        int a=V[i-1].first, b=V[i-1].second;
        if (find(a) == find(b)) {
            cout << i;
            return 0;
        } 
        merge(a, b);
    }

    cout << 0;
    return 0;
}