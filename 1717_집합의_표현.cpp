// https://www.acmicpc.net/problem/1717

#include <iostream>

using namespace std;

int* disjoint_set;
int* ran;

int find(int n) {
    if (disjoint_set[n] == n) return n;
    return disjoint_set[n] = find(disjoint_set[n]);
}

void merge(int v, int w) {
    v = find(v);
    w = find(w);
    if (v==w) return;
    if (ran[v] > ran[w]) swap(v, w); 
    disjoint_set[v]=w;
    if (ran[v] == ran[w]) ran[w]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    disjoint_set = (int*)malloc((n+1)*sizeof(int));
    ran = (int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<=n;i++) disjoint_set[i]=i;

    for(int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 0) merge(b, c);
        else (find(b)==find(c))?cout << "YES" << '\n' : cout <<"NO" << '\n';
    }
}