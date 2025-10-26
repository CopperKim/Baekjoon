#include <bits/stdc++.h>

using namespace std;

struct Node {
    long long value; 
    long long propa; 
}; 

const int MAX = 1000001; 
int N, M, K; 
long long nums[MAX+2]; 
Node tree[2*MAX+3];

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx].value = nums[l]; 
        tree[idx].propa = 0; 
        return;
    }
    int m = (l + r) / 2;
    build(idx * 2,     l,   m);
    build(idx * 2 + 1, m+1, r);
    tree[idx].value = tree[idx*2].value + tree[idx*2+1].value; 
    tree[idx].propa = 0;
}

void push(int idx, int l, int r) {
    if (tree[idx].propa == 0) return;
    tree[idx].value += tree[idx].propa * (r - l + 1);
    if (l != r) {
        tree[idx*2].propa += tree[idx].propa;
        tree[idx*2 + 1].propa += tree[idx].propa;
    }
    tree[idx].propa = 0;
}

void update(int idx, int l, int r, int ql, int qr, long long val) {
    push(idx, l, r); 
    if (qr < l || r < ql) return; 
    if (ql <= l && r <= qr) { 
        tree[idx].propa += val; 
        push(idx, l, r); 
        return;
    }
    int m = (l + r) / 2;
    update(idx*2, l, m, ql, qr, val);
    update(idx*2 + 1, m+1, r, ql, qr, val);
    tree[idx].value = tree[idx*2].value + tree[idx*2+1].value; 
}

long long query(int idx, int l, int r, int ql, int qr) {
    push(idx, l, r);
    if (qr < l || r < ql) return 0; 
    if (ql <= l && r <= qr) return tree[idx].value; 
    int m = (l + r) / 2;
    return query(idx*2, l, m, ql, qr) + query(idx*2+1, m+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i) cin >> nums[i];
    build(1, 1, N); 

    for (int i = 0; i < M + K; ++i) {
        int a; 
        cin >> a;
        if (a == 1) {
            int b, c; long long d;
            cin >> b >> c >> d;
            if (b > c) swap(b, c); 
            update(1, 1, N, b, c, d);
        } else {
            int b, c; 
            cin >> b >> c;
            if (b > c) swap(b, c);
            cout << query(1, 1, N, b, c) << '\n'; 
        }
    }
    return 0;
}