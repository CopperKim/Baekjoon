// https://www.acmicpc.net/problem/11401

#include <iostream>

using namespace std;

long long n, k; 
long long kfac=1;
long long bunja=1;
long long divisor = 1000000007;

long long func(long long jisu) {
    if (jisu == 1) return kfac;
    long long m = func(jisu/2);
    if (jisu %2 == 0) return m*m%divisor;
    return (m*m%divisor)*kfac%divisor;
}

int main() {
    cin >> n >> k;
    for(long long i=1;i<=k;i++) {
        bunja = bunja * (n+1-i) % divisor;
        kfac = kfac * i % divisor;
    }
    cout << bunja * func(divisor-2) % divisor;
}