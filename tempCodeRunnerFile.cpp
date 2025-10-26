#include <bits/stdc++.h>

using namespace std;

class Tree {
public : 
    long long value; 
    unique_ptr<Tree> left, right; 

    Tree(int *arr, int s, int e) {
        if (s == e) {
            value = arr[s]; 
            return; 
        }

        int m = (s+e)/2; 
        left = make_unique<Tree>(arr, s, m); 
        right = make_unique<Tree>(arr, m+1, e); 

        value = (left -> value) + (right -> value); 
        return; 
    }

    void update(int ql, int qr, long long delta, int l, int r) {
        if (qr < l || r < ql) return; 
        if (l == r) { value += delta; return; } 
        int m = (l + r) / 2;
        left->update(ql, qr, delta, l, m);
        right->update(ql, qr, delta, m+1, r);
        value = left->value + right->value;
    }

    long long sum(int ql, int qr, int l, int r) const {
        if (qr < l || r < ql) return 0; 
        if (ql <= l && r <= qr) return value; 
        int m = (l + r) / 2;
        return left->sum(ql, qr, l, m) + right->sum(ql, qr, m+1, r);
    }
};

int N, M, K; 
int arr[1000001]; 

int main() {
    cin >> N >> M >> K; 
    for(int i=0;i<N;i++) cin >> arr[i]; 

    Tree segment(arr, 0, N-1); 

    for(int i=0;i<M+K;i++) {
        int op; cin >> op; 
        if (op == 1) {
            int a, b, c; cin >> a >> b >> c; 
            segment.update(a-1, b-1, c, 0, N-1);
        } else if (op == 2) {
            int a, b; cin >> a >> b;
            cout << segment.sum(a-1, b-1, 0, N-1) << '\n';
        }
    }
}