#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int find(int idx, vector<int>& V) {
    if (V[idx] == idx) return idx;
    else return V[idx] = find(V[idx], V);
}

void merge(int a, int b, vector<int>& V) {
    a = find(a, V);
    b = find(b, V);
    if (a == b) return;
    V[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, K; cin >> N >> M >> K;
    vector<int> V(M), disjoint(M);
    vector<int> C(K);
    for(int& i : V) cin >> i;
    for(int i=0;i<M;i++) disjoint[i] = i;

    sort(V.begin(), V.end());

    for(int i=0;i<K;i++) {
        int c; cin >> c;
        int a = find(upper_bound(V.begin(), V.end(), c)-V.begin(), disjoint);
        cout << V[a] << '\n';
        merge(a, a+1, disjoint);
    }
}