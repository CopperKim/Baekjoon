// https://www.acmicpc.net/problem/10986

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m; cin >> n >> m;
    long long sums[1000007];
    sums[0] = 0;
    long long mods[1003]={};
    for(long long i=0;i<n;i++) {
        long long input; cin >> input;
        sums[i+1] = sums[i] + input;
        mods[sums[i+1] % m] ++;
    }
    long long res=mods[0];
    for(long long i=0;i<m;i++) res += mods[i]*(mods[i]-1)/2;
    cout << res;
}