#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int fact[11]; fact[0]=1;
    for(int i=1;i<=10;i++) fact[i] = fact[i-1]*i;

    cout << fact[n]/(fact[k]*fact[n-k]);
}