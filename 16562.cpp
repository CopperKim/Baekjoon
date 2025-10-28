// https://www.acmicpc.net/problem/16562

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int disjoint_set[10001];

int find(int n) {
    if (disjoint_set[n] == n) return n;
    return find(disjoint_set[n]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	disjoint_set[u] = v;
}

int main() {
    int n, m, k; cin >> n >> m >> k; 
    
    int pay[10001];
    for(int i=1;i<=n;i++) cin >> pay[i];

    for(int i=1;i<=n;i++) disjoint_set[i] = i;

    for(int i=1;i<=m;i++) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    int money[10001]={};

    for(int i=1;i<=n;i++) {
        int root; root=find(i);
        if (money[root] == 0) money[root] = pay[i];
        else money[root] = min(money[root], pay[i]);
    }

    int total=0;
    for(int i=1;i<=n;i++) total+=money[i];
    if (total <= k) cout << total;
    else cout << "Oh no";
}