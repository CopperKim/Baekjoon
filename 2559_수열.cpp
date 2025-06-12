// https://www.acmicpc.net/problem/2559

#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int sums[100006]; sums[0] = 0;
    for(int i=0;i<n;i++) {
        int input; cin >> input;
        sums[i+1] = sums[i] + input;
    }
    int maxa=sums[k];
    for(int i=1;i<=n-k;i++) {
        maxa = max(maxa, sums[k+i]-sums[i]);
    }
    cout << maxa;
}