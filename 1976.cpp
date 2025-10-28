// https://www.acmicpc.net/problem/1976\

#include <iostream>
#include <vector>

using namespace std;

int map[201][201];
int disjoint_set[201]={};

int find(int n) {
    if (disjoint_set[n] == n) return n;
    return find(disjoint_set[n]);
}

void merge(int a, int b) {
    int v, w; 
    v=find(a); w=find(b);
    if (v!=w) disjoint_set[v]=w;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i=1;i<n;i++) {
        disjoint_set[i]=i;
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        int a; cin >> a;
        if (a) merge(i, j);
    }
    vector<int> travel; 
    for(int i=1;i<=m;i++) {
        int a; cin >> a; travel.push_back(a);
    }

    int root = find(travel[0]);
    for(int i=1;i<m;i++) {
        if (root!=find(travel[i])) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}