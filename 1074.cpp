#include <iostream>

using namespace std;

long long Z(int N, int r, int c) {
    if (N == 0) return 0;
    long long res=0;
    if (r >= (1 << (N-1))) {
        res += (1 << (2*N-1));
        r -= (1 << (N-1));
    }
    if (c >= (1 << (N-1))) {
        res += (1 << (2*N-2));
        c -= (1 << (N-1));
    }

    // cout << res << ' ';
    return res + Z(N-1, r, c);
}

int main() {
    long long N, r, c; 
    cin >> N >> r >> c;

    cout << Z(N, r, c);
}