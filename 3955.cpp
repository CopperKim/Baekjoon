#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const long long MAX = 1000000000; 

// c | (kx+1) 인 x를 적어도 하나 구해라. 단 kx+1 < 10^9 
// extended euclidian algorithm 

tuple<long long,long long,long long> exgcd(long long a, long long b){
    long long s0=1, t0=0, r0=a;
    long long s1=0, t1=1, r1=b;
    while(r1!=0){
        long long q = r0 / r1;
        long long r2 = r0 - q*r1; r0=r1; r1=r2;
        long long s2 = s0 - q*s1; s0=s1; s1=s2;
        long long t2 = t0 - q*t1; t0=t1; t1=t2;
    }
    return {r0, s0, t0};
}

int main() {
    long long t; cin >> t; 

    while(t--) {
        long long k, c; 
        cin >> k >> c;

        auto [g, s, t] = exgcd(c, k); 
        if(g != 1){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        long long y = s % k;
        if(y <= 0) y += k;

        long long x = (c*y - 1) / k;
        if(x <= 0){
            y += k;
            x += c;
        }

        if(y <= MAX) cout << y << "\n";
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}