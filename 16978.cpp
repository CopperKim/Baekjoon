#include <bits/stdc++.h>

using namespace std;

int N, M; 
const int MAX = 100002; 
long long nums[MAX]; 
long long seg[2*MAX]; 

void construct(int idx, int s, int e) {
    if (s == e) {
        seg[idx] = nums[s]; 
        return; 
    }

    int m = (s+e)/2; 
    construct(2*idx, s, m); 
    construct(2*idx+1, m+1, e); 
    seg[idx] = seg[2*idx]+seg[2*idx+1]; 
    return; 
}

void update(int idx, int l, int r, int tar, int val) {
    if (tar < l || tar > r) return; 
    if (l == tar && r == tar) {
        seg[idx] = val; 
        return; 
    }

    int m = (l+r)/2; 
    if (tar <= m) update(2*idx, l, m, tar, val); 
    else update(2*idx+1, m+1, r, tar, val); 

    seg[idx] = seg[2*idx]+seg[2*idx+1]; 
    return; 
}

long long query(int idx, int l, int r, int s, int e) {
    if (e < l || s > r) return 0; 
    if (s <= l && r <= e) return seg[idx]; 

    int m = (l+r)/2; 
    return query(2*idx, l, m, s, e)+query(2*idx+1, m+1, r, s, e); 
}

int main() {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> nums[i]; 

    construct(1, 1, N); 

    cin >> M;
    int count = 0; 
    vector<tuple<int, int, int>> updateQuery; 
    vector<tuple<int, int, int, int>> sumQuery; 
    for(int i=1;i<=M;i++) {
        int a; cin >> a; 
        if (a == 1) {
            int b, c; cin >> b >> c; 
            updateQuery.push_back({b, c, i});
        } else {
            int b, c, d; cin >> b >> c >> d; 
            sumQuery.push_back({b, c, d, count++});  
        }
    } 

    int iter = 0; 
    sort(sumQuery.begin(), sumQuery.end()); 
    vector<long long> res(sumQuery.size()); 

    while(1) {
        const auto &[b2, c2, d2, order] = sumQuery[iter]; 
        if (b2 != 0) break; 
        res[order] = query(1, 1, N, c2, d2); 
        iter ++; 
    }

    for(int i=0;i<updateQuery.size();i++) {
        const auto &[b1, c1, j] = updateQuery[i]; 
        update(1, 1, N, b1, c1); 
        while(iter < sumQuery.size()) {
            const auto &[b2, c2, d2, order] = sumQuery[iter]; 
            if (b2 > i+1) break; 
            res[order] = query(1, 1, N, c2, d2); 
            iter++; 
        }
    }

    for(long long i : res) cout << i << '\n'; 
}